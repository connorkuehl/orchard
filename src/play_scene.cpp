#include <SFML/Window/Event.hpp>

#include "play_scene.h"

PlayScene::PlayScene(sf::RenderWindow& window)
: Scene{window}
{
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
    spawner_.update(elapsed);
}

void PlayScene::draw()
{
    window_.clear();
    window_.draw(spawner_);
    window_.display();
}

