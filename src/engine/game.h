#ifndef ORCHARD_GAME_H
#define ORCHARD_GAME_H

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "scene_manager.h"

namespace
{
    const int DEFAULT_WIDTH = 800;
    const int DEFAULT_HEIGHT = 600;
}

class Game
{
    public:
        Game(const std::string& name, unsigned int width = DEFAULT_WIDTH,
                unsigned int height = DEFAULT_HEIGHT);
        void run();
    private:
        sf::RenderWindow window_;
        SceneManager sceneManager_;
};

#endif // ORCHARD_GAME_H

