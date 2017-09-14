#ifndef ORCHARD_GAME_H
#define ORCHARD_GAME_H

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "scene_manager.h"
#include "../game_constants.h"

class Game
{
    public:
        Game(const std::string& name);
        void run();
    private:
        sf::RenderWindow window_;
        SceneManager sceneManager_;
};

#endif // ORCHARD_GAME_H

