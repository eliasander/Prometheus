<img src="./assets/title_upscaled.png" alt="drawing" width="100%"/>


<div align="center">
  <h2>
    Grand engines, like great fires, begin with the smallest spark.
  </h2>
</div>

# Naming

## Functions
Written with snake_case, for example:  
```
long long time_ms_get();
```

Functions should ALWAYS be written by how they are used:  
* [type] [component] _ [type] _ [action]  

Or something similiar, here are some examples:  
```
 SDL_Window* window_create();  
```

This function returns **SDL_Window*** as the [type], [component] is **window** and the [action] is **create**

---
Functions dont necessarily have to be written in this exact way, some exceptions are:
```
void draw_rectangle();  
```

The most important part is that functions dont collide, like:
```
void get_time_ms();
void get_number();
```

Both these function include **get** firstly which results with the language server either completing with **get_number** or **get_time**.  
A better way would be:
```
void time_ms_get();
void number_get();
```


## Variables
Variables are written with lower CamelCase, for example:  
```
int positionForPlayer;
bool isButtonPressed;
```

## Constants
Constants are written with UPPER_SNAKE_CASE for example:

```
#define TILE_SIZE 200
#define BASE_WIDTH 1920
#define BASE_HEIGHT 1080
```


# Coding
## Variables
1. Declare variables of the same type on the same line if possible.
2. All variables defined inside a scope should always be defined at the top, for example:

```
int function() {
    int i = 0;
    int y;
    // Empty line here
    ...
}
```
3. Variables should NEVER be a single character outside of an interation variable.
4. Avoid global variables when possible.
5. Functions that can fail should always return an error code or bool.
