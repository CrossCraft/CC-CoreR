#include <CC/core.h>
#include <stdlib.h>
#include <stdio.h>

static WorldData CC_GLOBAL_world_data;

void CC_World_Init(size_t x, size_t y, size_t z) {
    CC_GLOBAL_world_data.x = x;
    CC_GLOBAL_world_data.y = y;
    CC_GLOBAL_world_data.z = z;
    CC_GLOBAL_world_data.blocks = (block_t*)malloc(x * y * z * sizeof(block_t));
}

void CC_World_Term(void) {
    free(CC_GLOBAL_world_data.blocks);
}

void CC_World_Generate(void) {
    fprintf(stdout, "CC_World_Generate\n");
}

void CC_World_GetChunkSize(size_t* x, size_t* y, size_t* z) {
    *x = CC_GLOBAL_world_data.x / 16;
    *y = CC_GLOBAL_world_data.y / 16;
    *z = CC_GLOBAL_world_data.z / 16;
}

void CC_World_GetSize(size_t* x, size_t* y, size_t* z) {
    *x = CC_GLOBAL_world_data.x;
    *y = CC_GLOBAL_world_data.y;
    *z = CC_GLOBAL_world_data.z;
}

WorldData* CC_World_GetData(void) {
    return &CC_GLOBAL_world_data;
}

void CC_World_GetBlock(size_t x, size_t y, size_t z, block_t* block) {
    *block = CC_GLOBAL_world_data.blocks[CC_WIDX(x, y, z, &CC_GLOBAL_world_data)];
}

void CC_World_SetBlock(size_t x, size_t y, size_t z, block_t block) {
    CC_GLOBAL_world_data.blocks[CC_WIDX(x, y, z, &CC_GLOBAL_world_data)] = block;
}
