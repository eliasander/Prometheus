
#include <raylib.h>
#include "textures.h"

#include <stdlib.h>


#define TEXTUREMANAGER_INITIAL_SIZE 16

typedef struct {
    Texture *tex;
    uint16_t count;
    uint16_t capacity;
} TextureManager;

TextureManager texMgr = {0};


bool texture_manager_initalize() {
    // Allocate initial memory in the Texture Manager
    texMgr.tex = malloc(TEXTUREMANAGER_INITIAL_SIZE*sizeof(TextureHandle));

    // Set capacity and count
    texMgr.capacity = TEXTUREMANAGER_INITIAL_SIZE;
    texMgr.count = 0;

    return true;
}

void texture_manager_size_check() {

    // Check if count is at capacity
    if (texMgr.count == texMgr.capacity) {

        // Double capacity and reallocate Texture Manager
        texMgr.capacity *= 2;
        texMgr.tex = realloc(texMgr.tex, texMgr.capacity*sizeof(TextureHandle));
    }
}

TextureHandle texture_load(const char* path) {
    // Define our variables
    Texture tex = LoadTexture(path);
    uint16_t id;

    // Check Texture Manager size;
    texture_manager_size_check();

    // Set id and set texture in Texture Manager
    id = texMgr.count;
    texMgr.tex[texMgr.count++] = tex;
    return (TextureHandle){
        id,
        (Vec2){
            tex.width,
            tex.height
        }
    };
}

void draw_texture(Vec2 pos, Vec2 size, TextureHandle texture) {

    // Get texture from texture manager
    Texture tex = texMgr.tex[texture.id];

    // Define texture source
    Rectangle source = {
        0,
        0,
        texture.size.x,
        texture.size.y
    };

    // Define texture destination
    Rectangle dest = {
        pos.x,
        pos.y,
        size.x,
        size.y
    };

    // Draw Texture
    DrawTexturePro(tex, source, dest, (Vector2){0,0}, 0, WHITE);
}

