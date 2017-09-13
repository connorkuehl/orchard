#include <SFML/Window/Event.hpp>

#include "play_scene.h"

PlayScene::PlayScene(sf::RenderWindow& window)
: Scene{window}
{
}

PlayScene::~PlayScene()
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

void PlayScene::update(sf::Time &elapsed)
{
}

void PlayScene::draw()
{
    window_.clear();
    window_.display();
}

