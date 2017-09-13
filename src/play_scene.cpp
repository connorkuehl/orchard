#include <SFML/Window/Event.hpp>

#include "play_scene.h"

PlayScene::PlayScene(sf::RenderWindow& window)
: Scene{window}
, player_{{0, 0}}
{
    resources_.load(player_);
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

void PlayScene::update(float elapsed)
{
    player_.update(elapsed);
}

void PlayScene::draw()
{
    window_.clear();
    window_.draw(player_);
    window_.display();
}

