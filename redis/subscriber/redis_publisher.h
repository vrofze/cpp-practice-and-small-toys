#ifndef REDIS_PUBLISHER_H
#define REDIS_PUBLISHER_H

#include <stdlib.h>
#include <assert.h>
#include <string>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
// #include <unistd.h>
// #include <pthread.h>
#include <semaphore.h>

class CRedisPublisher
{
public:
    CRedisPublisher();
    ~CRedisPublisher();

    bool init();
    bool uninit();
    bool connect();
    bool disconnect();

    bool publish(const std::string &channel_name,
                 const std::string &message);

private:
    event_base *_event_base;
    pthread_t _event_thread;
    sem_t _event_sem;
    redisAsyncContext *_redis_context;

    static void connect_callback(const redisAsyncContext *redis_context,
                                 int status);
    static void disconnect_callback(const redisAsyncContext *redis_context,
                                    int status);
    static void command_callback(redisAsyncContext *redis_context,
                                 void *reply, void *privdata);
    static void *event_thread(void *data);
    void *event_proc();
};

#endif
