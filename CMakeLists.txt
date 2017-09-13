cmake_minimum_required(VERSION 3.8)
project(Orchard)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(SFML REQUIRED graphics window system)

include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        src/main.cpp src/game.cpp src/scene.cpp src/scene_manager.cpp src/play_scene.cpp
        src/game_object.cpp src/player.cpp src/resources.cpp)

add_executable(Orchard ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
        ${SFML_LIBRARIES}
        )

