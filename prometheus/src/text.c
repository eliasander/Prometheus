
#include <raylib.h>
#include "text.h"

#include <stdlib.h>
#include <stdint.h>


#define FONTMANAGER_INITIAL_SIZE 16

typedef struct {
    Font *font;
    uint16_t count;
    uint16_t capacity;
} FontManager;

FontManager fontMgr = {0};


bool font_manager_initalize() {
    // Allocate initial memory in the Font Manager
    fontMgr.font = malloc(FONTMANAGER_INITIAL_SIZE*sizeof(FontHandle));

    // Set capacity and count
    fontMgr.capacity = FONTMANAGER_INITIAL_SIZE;
    fontMgr.count = 0;

    return true;
}

void font_manager_size_check() {

    // Check if count is at capacity
    if (fontMgr.count == fontMgr.capacity) {

        // Double capacity and reallocate Font Manager
        fontMgr.capacity *= 2;
        fontMgr.font = realloc(fontMgr.font, fontMgr.capacity*sizeof(FontHandle));
    }
}

FontHandle font_load(const char* path) {
    // Define our variables
    Font font = LoadFont(path);
    uint16_t id;

    // Check Font Manager size;
    font_manager_size_check();

    // Set id and set texture in Font Manager
    id = fontMgr.count;
    fontMgr.font[fontMgr.count++] = font;

    return (FontHandle){
        id
    };
}

void draw_text(const char* text, Vec2 pos, int fontSize, Color color) {
    DrawText(text, pos.x, pos.y, fontSize, color);
}

void draw_text_font(const char* text, FontHandle font, Vec2 pos, int fontSize, float spacing, Color color) {
    DrawTextEx(fontMgr.font[font.id], text, (Vector2){pos.x, pos.y}, fontSize, spacing, color);
}

int text_measure(const char *text, int fontSize) {
    return MeasureText(text, fontSize);
}
Vec2 text_measure_font(FontHandle font, const char *text, float fontSize, float spacing)  {
    Vector2 temp = MeasureTextEx(fontMgr.font[font.id], text, fontSize, spacing);

    return (Vec2){
        temp.x,
        temp.y
    };
}
