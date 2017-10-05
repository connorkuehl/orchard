#include <SFML/Window/Event.hpp>

#include "game.h"
#include "../play_scene.h"
#include "../main_menu_scene.h"

/**
 * @brief Instantiates the Game.
 * @param name The game's name -- this will be used in the game window title.
 */
Game::Game(const std::string &name)
: window_{sf::VideoMode{game::SCREEN_WIDTH, game::SCREEN_HEIGHT}, name.c_str()}
{
    window_.setFramerateLimit(60);
}

/**
 * @brief Runs the game.
 *
 * This method drives the game loop. The Game loop is built upon a
 * state machine for managing the game state (scenes). Once there
 * are no more scenes, the game will exit.
 */
void Game::run()
{
    // Set the entry scene.
    sceneManager_.transition(std::make_unique<MainMenuScene>(window_, sceneManager_), false);
    sceneManager_.makeTransition();

    // Game loop
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

        if (sceneManager_.awaitingTransition()) {
            sceneManager_.makeTransition();
        }
    }
}
