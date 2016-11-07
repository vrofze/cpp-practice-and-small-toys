#include "redis_publisher.h"
#include <string.h>

CRedisPublisher::CRedisPublisher(): _event_base(0), _event_thread(0),
                                    _redis_context(0)
{
}

CRedisPublisher::~CRedisPublisher() { }

bool CRedisPublisher::init()
{
    _event_base = event_base_new();
    if(_event_base == NULL){
        printf(": Create redis event failed.\n");
        return false;
    }

    memset(&_event_sem, 0, sizeof(_event_sem));
    int ret = sem_init(&_event_sem, 0, 0);
    if(ret != 0){
        printf(": Init sem failed.\n");
    }

    return true;
}

bool CRedisPublisher::uninit()
{
    _event_base = NULL;

    sem_destroy(&_event_sem);
    return true;
}

bool CRedisPublisher::connect()
{
    _redis_context = redisAsyncConnect("127.0.0.1", 6379);

    if(_redis_context == NULL){
        printf(": Connect redis failed.\n");
        return false;
    }

    if(_redis_context->err){
        printf(": Connect redis error: %d, %s\n",
               _redis_context->err, _redis_context->errstr);
        return false;
    }

    // attach the event;
    redisLibeventAttach(_redis_context, _event_base);

    int ret = pthread_create(&_event_thread, 0, &CRedisPublisher::event_thread, this);
    if(ret != 0){
        printf(": Create event thread failed.\n");
        disconnect();
        return false;
    }

    redisAsyncSetConnectCallback(_redis_context,
                              &CRedisPublisher::connect_callback);
    redisAsyncSetDisconnectCallback(_redis_context,
                                 &CRedisPublisher::disconnect_callback);

    sem_post(&_event_sem);
    return true;
}

bool CRedisPublisher::disconnect()
{
    if (_redis_context)
    {
        redisAsyncDisconnect(_redis_context);
        redisAsyncFree(_redis_context);
        _redis_context = NULL;
    }

    return true;
}

bool CRedisPublisher::publish(const std::string &channel_name,
                              const std::string &message)
{
    int ret = redisAsyncCommand(_redis_context,
                                &CRedisPublisher::command_callback, this, "PUBLISH %s %s",
                                channel_name.c_str(), message.c_str());
    if (REDIS_ERR == ret)
    {
        printf("Publish command failed: %d\n", ret);
        return false;
    }

    return true;
}

void CRedisPublisher::connect_callback(const redisAsyncContext *redis_context,
                                       int status)
{
    if (status != REDIS_OK)
    {
        printf(": Error: %s\n", redis_context->errstr);
    }
    else
    {
        printf(": Redis connected!\n");
    }
}

void CRedisPublisher::disconnect_callback(
    const redisAsyncContext *redis_context, int status)
{
    if (status != REDIS_OK)
    {
        printf(": Error: %s\n", redis_context->errstr);
    }
}

void CRedisPublisher::command_callback(redisAsyncContext *redis_context,
                                       void *reply, void *privdata)
{
    printf("command callback.\n");
}

void *CRedisPublisher::event_thread(void *data)
{
    if (NULL == data)
    {
        printf(": Error!\n");
        assert(false);
        return NULL;
    }

    CRedisPublisher *self_this = reinterpret_cast<CRedisPublisher *>(data);
    return self_this->event_proc();
}


void *CRedisPublisher::event_proc()
{
    sem_wait(&_event_sem);

    event_base_dispatch(_event_base);

    return NULL;
}
