
#include "src/input.h"
#include <prometheus.h>

#include <stdbool.h>
#include <stdio.h>

#define BASE_WIDTH 960
#define BASE_HEIGHT 540
#define CLEAR_COLOR (Color){100,100,100,255}


#ifdef _WIN32
    #include <windows.h>
#else
    #include <time.h>
#endif





int main() {

    Vec2 window_size = {
        BASE_WIDTH,
        BASE_HEIGHT
    };
    window_init(window_size, "Prometheus");
    
    texture_manager_initalize();

    TextureHandle title = texture_load("./assets/title.png");

    while (!window_should_close()) {

        draw_begin();

        draw_background_clear(CLEAR_COLOR);

        draw_texture((Vec2){(BASE_WIDTH-title.size.x*10)/2,50}, (Vec2){title.size.x*10, title.size.y*10}, title);

        draw_end();


    }

    window_close();

}