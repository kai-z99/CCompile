#include <stdio.h>
#include <time.h>
#include "arena.h"

int main()
{
    const int allocations = 10000000;

    Arena* a = CreateArena(allocations * sizeof(int));
    Arena* b = CreateArena(allocations * sizeof(long));

    clock_t start = clock();

    for (int i = 0; i < allocations; i++)
    {
        int* j = (int*)AllocateArena(a, sizeof(int));
        *j = i;

        long* h = (long*)AllocateArena(b, sizeof(long));
        *h = i;
    }
    
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time passed using arena allocation: %.6f s\n", elapsedSeconds);

    PrintArenaStatus(a);
    PrintArenaStatus(b);

    FreeArena(a);
    FreeArena(b);

    start = clock();

    for (int i = 0; i < allocations; i++)
    {
        int* j = (int*)malloc(sizeof(int));
        *j = i;

        long* h = (long*)malloc(sizeof(long));
        *h = i;
    }

    end = clock();
    double elapsedSeconds2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time passed without arena allocation: %.6f s\n", elapsedSeconds2);

    printf("Difference: %.2f%%\n", 100 * (elapsedSeconds2 / elapsedSeconds));



    
    return 0;
}