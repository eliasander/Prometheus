#ifdef __unix__

#include <time.h>
#include "misc.h"

long long time_ms_get(void) {
    long long returnValue = 0;

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    returnValue = (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

    return returnValue;
}
long long time_s_get(void) {
    long long returnValue = 0;

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    returnValue = (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

    return returnValue/1000.0f;
}

#endif
