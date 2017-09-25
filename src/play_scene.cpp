#include <SFML/Window/Event.hpp>

#include "play_scene.h"
#include "game_constants.h"

PlayScene::PlayScene(sf::RenderWindow& window, SceneManager & sceneManager)
: Scene{window, sceneManager}
, player_{{(game::SCREEN_WIDTH / 2) + 16, game::SCREEN_HEIGHT - 66}}
, score_{0}
{
    background_.setTexture(resources_.loadTexture("res/background.png"));
    resources_.load(player_);
    Apple apple{{32, 0}};
    resources_.load(apple);
    spawner_.attachPrototype(apple);
}

void PlayScene::interact()
{
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            shouldExit(true);
        }
    }
}

void PlayScene::update(float elapsed)
{
    spawner_.isSpawnCollidingWith(player_);
    spawner_.update(elapsed);
    player_.update(elapsed);
}

void PlayScene::draw()
{
    window_.clear();
    window_.draw(background_);
    window_.draw(spawner_);
    window_.draw(player_);
    window_.display();
}

