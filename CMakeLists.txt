cmake_minimum_required(VERSION 3.8)
project(Orchard)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(SFML REQUIRED graphics window system)

include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        src/engine/game.cpp                     src/engine/game.h
        src/engine/scene.cpp                    src/engine/scene.h
        src/engine/scene_manager.cpp            src/engine/scene_manager.h
        src/engine/game_object.cpp              src/engine/game_object.h
        src/engine/resources.cpp                src/engine/resources.h
                                                src/engine/iloadable.h
        src/play_scene.cpp                      src/play_scene.h
        src/main_menu_scene.cpp                 src/main_menu_scene.h
        src/player.cpp                          src/player.h
        src/apple.cpp                           src/apple.h
        src/spawner.cpp                         src/spawner.h
        src/main.cpp                            src/game_constants.h
        )

add_executable(Orchard ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
        ${SFML_LIBRARIES}
        )

