#include <SFML/Window/Event.hpp>

#include "play_scene.h"

PlayScene::PlayScene(sf::RenderWindow& window)
: Scene{window}
, apple_{{32, 0}}
{
    resources_.load(apple_);
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
    spawner_.update();
    apple_.update(elapsed);
}

void PlayScene::draw()
{
    window_.clear();
    window_.draw(apple_);
    window_.display();
}

