#include <SFML/Window/Event.hpp>
#include "engine/scene_manager.h"
#include "main_menu_scene.h"
#include "play_scene.h"

MainMenuScene::MainMenuScene(sf::RenderWindow & window, SceneManager & sceneManager)
: Scene(window, sceneManager)
{
    mainMenu_.setTexture(resources_.loadTexture("res/main_menu.png"));
}

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

void MainMenuScene::update(float elapsed)
{
}

void MainMenuScene::draw()
{
    window_.clear();
    window_.draw(mainMenu_);
    window_.display();
}
