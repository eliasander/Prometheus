
#include <raylib.h>
#include "render.h"
#include "textures.h"


void draw_begin() {
    BeginDrawing();
}
void draw_background_clear(Color color) {
    
    ClearBackground(color);
}
void draw_end() {
    EndDrawing();
}



void draw_rectangle(Vec2 pos, Vec2 size, Color color) {
    DrawRectangle(pos.x, pos.y, size.x, size.y, color);
}

void draw_line(Vec2 start, Vec2 end, Color color) {
    DrawLine(start.x, start.y, end.x, end.y, color);
}