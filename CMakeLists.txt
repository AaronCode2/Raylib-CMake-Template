cmake_minimum_required(VERSION 3.10...3.50)

project(Aaron)

include(FetchContent)

set(RAYLIB_VERSION 5.5)

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

if(WIN32)

    target_sources(Tiny_Wonder PRIVATE Windows/app.rc)
    target_link_options(Aaron PRIVATE $<$<CONFIG:Release>:-mwindows>)
elseif(APPLE)

    target_link_options(Aaron PRIVATE $<$<CONFIG:Release>:-MACOSX_BUNDLE>)
endif()

target_compile_definitions(Aaron PUBLIC $<$<CONFIG:Debug>:DEBUG_ENABLED>)
target_link_libraries(Aaron raylib)

message("Operation Complete! Configured Correctly!")

if("${PLATFORM}" STREQUAL "Web")

    message(FATAL_ERROR "Do not build in this project in the Web as it doesn't work!")
endif()

if(APPLE)

    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()