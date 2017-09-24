#include <SFML/Window/Event.hpp>
#include "game.h"
#include "../play_scene.h"
#include "../main_menu_scene.h"

Game::Game(const std::string& name)
: window_{sf::VideoMode{game::SCREEN_WIDTH, game::SCREEN_HEIGHT}, name.c_str()}
{
    window_.setFramerateLimit(60);
}

void Game::run()
{
    sceneManager_.push(new MainMenuScene{window_, sceneManager_});

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
