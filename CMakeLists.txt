cmake_minimum_required(VERSION 3.31.6)
project(Prometheus VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# --- 1. Fetch Dependencies ---
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES     OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# --- 2. Library Sources ---
file(GLOB LIB_SOURCES CONFIGURE_DEPENDS
    prometheus/src/*.c
    prometheus/src/os/*.c
)

# Files allowed to include <raylib.h> inside the library
set(RAYLIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/prometheus/src/core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/prometheus/src/textures.c
    ${CMAKE_CURRENT_SOURCE_DIR}/prometheus/src/render.c
    ${CMAKE_CURRENT_SOURCE_DIR}/prometheus/src/input.c
)
# --- 3. Define the Library ---
add_library(Prometheus STATIC ${LIB_SOURCES})
add_library(Prometheus::Prometheus ALIAS Prometheus)

# Include directories for consumers vs building
target_include_directories(Prometheus PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/prometheus>
    $<INSTALL_INTERFACE:include>
)

# Link dependencies privately
target_link_libraries(Prometheus PRIVATE
    raylib
    m
)

# Only your internal wrapper files get raylib's headers
set_source_files_properties(${RAYLIB_SOURCES} PROPERTIES
    INCLUDE_DIRECTORIES "$<TARGET_PROPERTY:raylib,INTERFACE_INCLUDE_DIRECTORIES>"
)


# --- 4. Optional Test / Game Compilation (e.g., using main.h) ---
if(PROJECT_IS_TOP_LEVEL)
    set(PROMETHEUS_BUILD_TEST_DEFAULT ON)
else()
    set(PROMETHEUS_BUILD_TEST_DEFAULT OFF)
endif()

option(PROMETHEUS_BUILD_TEST "Build test/game executable using main.h" ${PROMETHEUS_BUILD_TEST_DEFAULT})

if(PROMETHEUS_BUILD_TEST)
    # Gather your game/test sources (e.g., game0/*.c containing main.h logic)
    file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
        game0/*.c
    )

    add_executable(prometheus_test ${TEST_SOURCES})

    # Link your test executable to your Prometheus library
    target_link_libraries(prometheus_test PRIVATE
        Prometheus::Prometheus
    )

    # Include directories needed for the test code
    target_include_directories(prometheus_test PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/prometheus
        ${CMAKE_CURRENT_SOURCE_DIR}/game0
    )

    # Copy assets for the test executable runtime
    add_custom_command(TARGET prometheus_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E rm -rf
            "$<TARGET_FILE_DIR:prometheus_test>/assets"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:prometheus_test>/assets"
    )
endif()