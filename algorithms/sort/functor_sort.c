#include <stdio.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b)
{
    return (0 - (*(int*)a - *(int*)b));
}

int main()
{
    int list[5] = { 54, 21, 11, 67, 22 };
    qsort((void*)list, 5, sizeof(list[0]), sort_function);
    for(int i = 0 ; i < 5; ++i)
        printf("%i ", list[i]);

    return 0;
}
