#include <hiredis/hiredis.h>
#include <iostream>
#include <string>

int main()
{
    struct timeval timeout = {2, 0};

    redisContext *p_redis_context = (redisContext *)redisConnectWithTimeout("127.0.0.1", 6379, timeout);

    if((p_redis_context == nullptr) || (p_redis_context->err)){
        if(p_redis_context)
            std::cout << "Connect error:" << p_redis_context->errstr << std::endl;
        else
            std::cout << "connect error: can't allocatte redis context" << std::endl;
        return -1;
    }

    // exec info command
    redisReply *p_redis_reply= (redisReply *)redisCommand(p_redis_context, "auth frost");

    std::cout << p_redis_reply->str << std::endl;

    p_redis_reply= (redisReply *)redisCommand(p_redis_context, "info");
    std::cout << p_redis_reply->str << std::endl;
    // clear p_redis_reply
    freeReplyObject(p_redis_reply);

    return 0;
}
