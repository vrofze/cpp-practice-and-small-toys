#include "redis_publisher.h"
#include <unistd.h>

int main()
{
    CRedisPublisher publisher;

    bool ret = publisher.init();
    if (!ret)
    {
        printf("Init failed.\n");
        return 0;
    }

    ret = publisher.connect();
    if (!ret)
    {
        printf("connect failed.");
        return 0;
    }

    while (true)
    {
        publisher.publish("test-channel", "Hello frost!");
        sleep(1);
    }

    publisher.disconnect();
    publisher.uninit();
    return 0;
}
