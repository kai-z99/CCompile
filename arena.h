    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>

    typedef struct Arena
    {
        size_t size;
        size_t used;
        char* arena;
    } Arena;

    Arena* CreateArena(size_t size);

    void FreeArena(Arena* a);

    void* AllocateArena(Arena* a, size_t size);

    void ResetArena(Arena* a);

    void PrintArenaStatus(Arena* a);