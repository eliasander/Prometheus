#ifndef PROMENTHEUS_IMAGE_H
#define PROMENTHEUS_IMAGE_H

#include <stdbool.h>
#include <stdint.h>

#define ImageID uint64_t

typedef struct {
    ImageID id;
} ImageHandle;

bool image_manager_initalize();

ImageHandle image_load(const char* path);


#endif
