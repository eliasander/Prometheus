#ifndef PROMENTHEUS_RENDER_H
#define PROMENTHEUS_RENDER_H

#include "core.h"

void draw_begin();
void draw_background_clear(Color color);
void draw_end();

void draw_rectangle(Vec2 pos, Vec2 size, Color color);
void draw_line(Vec2 start, Vec2 end, Color color);


#endif