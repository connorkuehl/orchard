cmake_minimum_required(VERSION 3.8)
project(Orchard)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})

set(SOURCE_FILES 
    src/main.cpp
    src/sdl_application.cpp
    src/game.cpp
    src/window.cpp
    src/renderer.cpp
    )
add_executable(Orchard ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    )

