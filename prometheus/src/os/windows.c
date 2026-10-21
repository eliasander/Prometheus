#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "misc.h"

long long time_ms_get(void) {
    long long returnValue = 0;
    #ifdef _WIN32

    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    ULARGE_INTEGER ull;
    ull.LowPart = ft.dwLowDateTime;
    ull.HighPart = ft.dwHighDateTime;
    //FILETIME is 100-ns intervals since 1601; convert to Unix ms epoch
    returnValue = (long long)(ull.QuadPart / 10000ULL - 11644473600000ULL);

    #else

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    returnValue = (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

    #endif

    return returnValue;
}
long long time_s_get(void) {
    long long returnValue = 0;
    #ifdef _WIN32

    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    ULARGE_INTEGER ull;
    ull.LowPart = ft.dwLowDateTime;
    ull.HighPart = ft.dwHighDateTime;
    // FILETIME is 100-ns intervals since 1601; convert to Unix ms epoch
    returnValue = (long long)(ull.QuadPart / 10000ULL - 11644473600000ULL);

    #else

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    returnValue = (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

    #endif

    return returnValue/1000.0f;
}

#endif
