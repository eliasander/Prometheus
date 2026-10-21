#ifndef PROMENTHEUS_TEXTURES_H
#define PROMENTHEUS_TEXTURES_H


#include "core.h"

#include <stdbool.h>
#include <stdint.h>

#define TextureID uint64_t

typedef struct {
    TextureID id;
    Vec2 size;
} TextureHandle;

bool texture_manager_initalize();
TextureHandle texture_load(const char* path);
bool texture_unload(TextureHandle texture);


void draw_texture(Vec2 pos, Vec2 size, TextureHandle texture);


#endif