cmake_minimum_required(VERSION 3.28)

project(Aaron)

include(FetchContent)

set(RAYLIB_VERSION 4.2.0)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(
SOURCE_FILES

    src/main.cpp
)

add_executable(Aaron ${SOURCE_FILES})
target_link_libraries(Aaron raylib)

if ("${PLATFORM}" STREQUAL "Web")

    message(FATAL_ERROR "Do not build in this project in the Web as it doesn't work!")
endif()

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()