#include <SFML/Window/Event.hpp>
#include "engine/scene_manager.h"
#include "main_menu_scene.h"
#include "play_scene.h"

/**
 * Constructs the MainMenuScene and attaches the render window and scene manager to it.
 * @param window The Render Window that this Scene will be drawn to.
 * @param sceneManager The Scene Manager that will manage this Scene.
 */
MainMenuScene::MainMenuScene(sf::RenderWindow &window, SceneManager &sceneManager)
: Scene(window, sceneManager)
{
    mainMenu_.setTexture(resources_.loadTexture("res/main_menu.png"));
}

/**
 * "Listens" for user interaction and transitions to a play state if it detects anything.
 */
void MainMenuScene::interact()
{
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            shouldExit(true);
        }
        else if (event.type == sf::Event::KeyPressed) {
            sceneManager_.transition(std::make_unique<PlayScene>(window_, sceneManager_));
        }
    }
}

/**
 * Updates the MainMenuState. Currently does nothing as there is no real logic to process.
 * @param elapsed The elapsed time for this game loop iteration.
 */
void MainMenuScene::update(float elapsed)
{
}

/**
 * Draws the Main Menu to the Window.
 */
void MainMenuScene::draw()
{
    window_.clear();
    window_.draw(mainMenu_);
    window_.display();
}
