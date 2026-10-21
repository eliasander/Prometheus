#ifndef PROMENTHEUS_CORE_H
#define PROMENTHEUS_CORE_H

#include <stdbool.h>

typedef struct {
    float x,y;
} Vec2;
typedef struct {
    float x,y,z;
} Vec3;

#ifndef RL_COLOR_TYPE
#define RL_COLOR_TYPE
typedef struct Color {
    unsigned char r, g, b, a;
} Color;
#endif

typedef enum {
    APP_FLAG_VSYNC_HINT         = 0x00000040,   // Set to try enabling V-Sync on GPU
    APP_FLAG_FULLSCREEN_MODE    = 0x00000002,   // Set to run program in fullscreen
    APP_FLAG_WINDOW_RESIZABLE   = 0x00000004,   // Set to allow resizable window
    APP_FLAG_WINDOW_UNDECORATED = 0x00000008,   // Set to disable window decoration (frame and buttons)
    APP_FLAG_WINDOW_HIDDEN      = 0x00000080,   // Set to hide window
    APP_FLAG_WINDOW_MINIMIZED   = 0x00000200,   // Set to minimize window (iconify)
    APP_FLAG_WINDOW_MAXIMIZED   = 0x00000400,   // Set to maximize window (expanded to monitor)
    APP_FLAG_WINDOW_UNFOCUSED   = 0x00000800,   // Set to window non focused
    APP_FLAG_WINDOW_TOPMOST     = 0x00001000,   // Set to window always on top
    APP_FLAG_WINDOW_ALWAYS_RUN  = 0x00000100,   // Set to allow windows running while minimized
    APP_FLAG_WINDOW_TRANSPARENT = 0x00000010,   // Set to allow transparent framebuffer
    APP_FLAG_WINDOW_HIGHDPI     = 0x00002000,   // Set to support HighDPI
    APP_FLAG_WINDOW_MOUSE_PASSTHROUGH = 0x00004000, // Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED
    APP_FLAG_BORDERLESS_WINDOWED_MODE = 0x00008000, // Set to run program in borderless windowed mode
    APP_FLAG_MSAA_4X_HINT       = 0x00000020,   // Set to try enabling MSAA 4X
    APP_FLAG_INTERLACED_HINT    = 0x00010000    // Set to try enabling interlaced video format (for V3D)
} AppConfigFlags;

// Create window and opengl context
void window_init(Vec2 size, const char *title);

// Close window and delete opengl context
void window_close();

// Check if window should close
bool window_should_close();

bool window_state_get(unsigned int flag);
void window_state_set(unsigned int flag);
void window_state_clear(unsigned int flag);

bool window_ready_get(void);
bool window_fullscreen_get(void);
bool window_hidden_get(void);
bool window_minimized_get(void);
bool window_maximized_get(void);
bool window_focused_get(void);
bool window_resized_get(void);
//
void window_fullscreen_toggle(void);
void window_fullscreen_borderless_toggle(void);
void window_maximize(void);
void window_minimize(void);
void window_restore(void);
//void window_icon(ImageHandle image);
void window_title_set(const char *title);
void window_position_set(Vec2 pos);
void window_monitor_set(int monitor);
void window_size_min(Vec2 minSize);
void window_size_max(Vec2 maxSize);
void window_size_set(Vec2 size);
void window_opacity_set(float opacity);
void window_focus_set(void);
void *window_handle_get(void);
//
int screen_width_get(void);
int screen_height_get(void);
int render_width_get(void);
int render_height_get(void);
//
int monitor_count_get(void);
int monitor_current_get(void);
Vec2 monitor_position_get(int monitor);
int monitor_width_get(int monitor);
int monitor_height_get(int monitor);
int monitor_physical_width_get(int monitor);
int monitor_physical_height_get(int monitor);
int monitor_refreshrate_get(int monitor);
Vec2 window_position_get(void);
Vec2 window_scale_get(void);
const char *monitor_name_get(int monitor);
void clipboard_set(const char *text);
const char* clipboard_get(void);
//ImageHandle clipboard_image_get(void);

void event_waiting_enable(void);
void event_waiting_disable(void);
//
void cursor_hide_set(bool value);
bool cursor_hide_get(void);

void cursor_enable_set(bool value);
bool cursor_onscreen_get(void);



// Returns previous frame execution time in milliseconds
float time_frame_ms_get();
// Returns previous frame execution time in seconds
float time_frame_s_get();
// Returns time in milliseconds since epoch
long long time_ms_get(void);
// Returns time in seconds since epoch
long long time_s_get(void);

void time_frame_fps_target(int fps);
#endif
