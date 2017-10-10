#ifndef ORCHARD_GAME_H
#define ORCHARD_GAME_H

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "scene_manager.h"
#include "../game_constants.h"

/**
 * @brief The game.
 */
class Game
{
    public:
        /// @brief Constructs the game with the given name.
        explicit Game(const std::string &name);
        /// @brief Runs the game loop.
        void run();
    private:
        sf::RenderWindow window_; ///< The main game window.
        SceneManager sceneManager_; ///< The game's scene manager.
};

#endif // ORCHARD_GAME_H
