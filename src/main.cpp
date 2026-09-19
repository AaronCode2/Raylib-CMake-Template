#include <iostream>
#include <nlohmann/json.hpp>
#define RAYLIB_NUKLEAR_IMPLEMENTATION
#include "raylib-nuklear.h"

using Json = nlohmann::json;

// Let's start coding! Press f5 to run

int main() {

    std::cout << "Hello World";

    return std::cin.get();
}