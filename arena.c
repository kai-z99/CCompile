#include "arena.h"

Arena* CreateArena(size_t size)
{
    Arena* a = (Arena*)malloc(sizeof(Arena));

    a->arena = (char*)malloc(size);
    a->size = size;
    a->used = 0;

    return a;
}

void FreeArena(Arena* a)
{
    if (a)
    {
        free(a->arena);
        free(a);
    }
}

void* AllocateArena(Arena *a, size_t size)
{
    if (a->used + size > a->size)
    {
        fprintf(stderr, "Out of memory in arena. Used: %zu, Requested: %zu, Total: %zu\n", a->used, size, a->size);
        exit(EXIT_FAILURE);
    }

    void* block = a->arena + a->used;
    a->used += size;

    return block;
}

void ResetArena(Arena *a)
{
    a->used = 0;
}

void PrintArenaStatus(Arena* a)
{
    printf("Total: %zu bytes\n", a->size);
    printf("Used: %zu bytes\n", a->used);
    printf("Availible: %zu bytes\n", a->size - a->used);

}
