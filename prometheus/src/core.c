
#include <raylib.h>
#include <prometheus.h>

void window_init(Vec2 size, const char *title) {
    InitWindow(size.x, size.y, title);
}
void window_close() {
    CloseWindow();
}
bool window_should_close() {
    return WindowShouldClose();
}

bool window_state_get(unsigned int flag) {
    return IsWindowState(flag);
}
void window_state_set(unsigned int flag) {
    SetWindowState(flag);
}
void window_state_clear(unsigned int flag) {
    ClearWindowState(flag);
}

bool window_ready_get(void) {
    return IsWindowReady();
}
bool window_fullscreen_get(void) {
    return IsWindowFullscreen();
}
bool window_hidden_get(void) {
    return IsWindowHidden();
}

bool window_minimized_get(void) {
    return IsWindowMinimized();
}
bool window_maximized_get(void) {
    return IsWindowMaximized();
}
bool window_focused_get(void) {
    return IsWindowFocused();
}
bool window_resized_get(void) {
    return IsWindowResized();
}

void window_fullscreen_toggle(void) {
    ToggleFullscreen();
}
void window_fullscreen_borderless_toggle(void) {
    ToggleBorderlessWindowed();
}
void window_maximize(void) {
    MaximizeWindow();
}
void window_minimize(void) {
    MinimizeWindow();
}
void window_restore(void) {
    RestoreWindow();
}
void window_title_set(const char *title) {
    SetWindowTitle(title);
}
void window_position_set(Vec2 pos) {
    SetWindowPosition(pos.x, pos.y);
}
void window_monitor_set(int monitor) {
    SetWindowMonitor(monitor);
}
void window_size_min(Vec2 minSize) {
    SetWindowMinSize(minSize.x, minSize.y);
}
void window_size_max(Vec2 maxSize) {
    SetWindowMaxSize(maxSize.x, maxSize.y);
}
void window_size_set(Vec2 size) {
    SetWindowSize(size.x, size.y);
}
void window_opacity_set(float opacity) {
    SetWindowOpacity(opacity);
}
void window_focus_set(void) {
    SetWindowFocused();
}
void *window_handle_get(void) {
    return GetWindowHandle();
}

int screen_width_get(void) {
    return GetScreenWidth();
}
int screen_height_get(void) {
    return GetScreenHeight();
}
int render_width_get(void) {
    return GetRenderWidth();
}
int render_height_get(void) {
    return GetRenderHeight();
}

int monitor_count_get(void) {
    return GetMonitorCount();
}
int monitor_current_get(void) {
    return GetCurrentMonitor();
}
Vec2 monitor_position_get(int monitor) {
    Vector2 pos = GetMonitorPosition(monitor);
    return (Vec2){pos.x, pos.y};
}
int monitor_width_get(int monitor) {
    return GetMonitorWidth(monitor);
}
int monitor_height_get(int monitor) {
    return GetMonitorHeight(monitor);
}
int monitor_physical_width_get(int monitor) {
    return GetMonitorPhysicalWidth(monitor);
}
int monitor_physical_height_get(int monitor) {
    return GetMonitorPhysicalHeight(monitor);
}
int monitor_refreshrate_get(int monitor) {
    return GetMonitorRefreshRate(monitor);
}
Vec2 window_position_get(void) {
    Vector2 pos = GetWindowPosition();
    return (Vec2){pos.x, pos.y};
}
Vec2 window_scale_get(void) {
    Vector2 scale = GetWindowScaleDPI();
    return (Vec2){scale.x, scale.y};
}
const char *monitor_name_get(int monitor) {
    return GetMonitorName(monitor);
}
void clipboard_set(const char *text) {
    SetClipboardText(text);
}
const char* clipboard_get(void) {
    return GetClipboardText();
}
//
void event_waiting_enable(void) {
    EnableEventWaiting();
}
void event_waiting_disable(void) {
    DisableEventWaiting();
}
void cursor_hide_set(bool value) {
    if (value)
        HideCursor();
    else
        ShowCursor();
}
bool cursor_hide_get(void) {
    return IsCursorHidden();
}

void cursor_enable_set(bool value) {
    if (value)
        EnableCursor();
    else
        DisableCursor();
}
bool cursor_onscreen_get(void) {
    return IsCursorOnScreen();
}
//

float time_frame_ms_get() {
    return GetFrameTime()/1000.0f;
}
float time_frame_s_get() {
    return GetFrameTime();
}

void time_frame_fps_target(int fps) {
    SetTargetFPS(fps);
}
