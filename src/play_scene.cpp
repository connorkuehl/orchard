#include <SFML/Window/Event.hpp>

#include "play_scene.h"

PlayScene::PlayScene(sf::RenderWindow& window)
: Scene{window}
{
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
}

void PlayScene::draw()
{
    window_.clear();
    window_.display();
}

