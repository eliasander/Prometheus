
#include "src/image.h"
#include <raylib.h>

#include <stdlib.h>
#include <stdint.h>


#define IMAGEMANAGER_INITIAL_SIZE 16

typedef struct {
    Image *image;
    uint16_t count;
    uint16_t capacity;
} ImageManager;

ImageManager imageMgr = {0};


bool image_manager_initalize() {
    // Allocate initial memory in the Image Manager
    imageMgr.image = malloc(IMAGEMANAGER_INITIAL_SIZE*sizeof(ImageHandle));

    // Set capacity and count
    imageMgr.capacity = IMAGEMANAGER_INITIAL_SIZE;
    imageMgr.count = 0;

    return true;
}

void image_manager_size_check() {

    // Check if count is at capacity
    if (imageMgr.count == imageMgr.capacity) {

        // Double capacity and reallocate Image Manager
        imageMgr.capacity *= 2;
        imageMgr.image = realloc(imageMgr.image, imageMgr.capacity*sizeof(ImageHandle));
    }
}

ImageHandle image_load(const char* path) {
    // Define our variables
    Image image = LoadImage(path);
    uint16_t id;

    // Check Image Manager size;
    image_manager_size_check();

    // Set id and set texture in Image Manager
    id = imageMgr.count;
    imageMgr.image[imageMgr.count++] = image;

    return (ImageHandle){
        id
    };
}

void image_unload(ImageHandle image) {
    // Check if given image is last in manager
    if (image.id == imageMgr.count) {
        // Just free pointer and reduce count by 1
        free(&imageMgr.image[image.id]);
        imageMgr.count--;
    } else {
        Image *temp;
        imageMgr.image = realloc(&imageMgr.image[image.id], (imageMgr.capacity-image.id)*sizeof(ImageHandle));
    }
}






void window_icon(ImageHandle image) {
    SetWindowIcon(imageMgr.image[image.id]);
}
ImageHandle clipboard_image_get(void) {
    GetClipboardImage();
}
