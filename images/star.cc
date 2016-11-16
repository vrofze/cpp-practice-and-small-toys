#include <stdio.h>
#include <stdlib.h>

const int w = 24;
const int h = 12;

int triangle(int x, int y)
{
    return abs(x) <= y;
}

int f(int x, int y)
{
    return triangle(x - 11, y) &&
        triangle((x + y / 3 * 3 + 3) % 6 - 2, y % 3);
}

int main()
{
    int x, y;
    for(y = 0; y < h; ++y){
        for(x = 0; x < w; ++x)
            printf(f(x, y)? "* " : "  ");
        puts("");
    }
}
