#include <SFML/Window/Event.hpp>

#include "game.h"
#include "play_scene.h"

Game::Game(const std::string& name, unsigned int width, unsigned int height)
: window_{sf::VideoMode{width, height}, name.c_str()}
{
}

void Game::run()
{
    sceneManager_.push(new PlayScene{window_});

    sf::Clock clock;
    auto last = clock.restart();
    while (sceneManager_.hasScenes()) {
        auto elapsed = clock.getElapsedTime();
        last = elapsed;

        auto currentScene = sceneManager_.top();

        currentScene->interact();
        currentScene->update(elapsed);
        currentScene->draw();

        if (currentScene->isExiting()) {
            sceneManager_.pop();
        }
    }
}
