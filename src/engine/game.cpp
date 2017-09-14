#include <SFML/Window/Event.hpp>

#include "game.h"
#include "../play_scene.h"

Game::Game(const std::string& name, unsigned int width, unsigned int height)
: window_{sf::VideoMode{width, height}, name.c_str()}
{
    window_.setFramerateLimit(60);
}

void Game::run()
{
    sceneManager_.push(new PlayScene{window_});

    sf::Clock clock;
    while (sceneManager_.hasScenes()) {
        auto currentScene = sceneManager_.top();

        currentScene->interact();
        auto elapsed = clock.restart().asSeconds();
        currentScene->update(elapsed);
        currentScene->draw();

        if (currentScene->isExiting()) {
            sceneManager_.pop();
        }
    }
}
