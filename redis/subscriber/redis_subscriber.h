#ifndef REDIS_SUBSCRIBER_H
#define REDIS_SUBSCRIBER_H

#include <stdlib.h>
#include <assert.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <string>
#include <semaphore.h>
#include <boost/tr1/functional.hpp>

class CRedisSubscriber
{
public:
    typedef std::tr1::function<void (const char *, const char *, int )> NotifyMessageFn;

    CRedisSubscriber();
    ~CRedisSubscriber();

    bool init(const NotifyMessageFn &fn);
    bool uninit();
    bool connect();
    bool disconnect();

    bool subscribe(const std::string &channel_name);

private:
    event_base *_event_base;
    pthread_t _event_thread;
    sem_t _event_sem;
    redisAsyncContext *_redis_context;

    NotifyMessageFn _notify_message_fn;

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
