#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <ctime>

int random(double start, double end)
{
    return start + (end - start) * rand() / (RAND_MAX);
}

#endif // random-h
