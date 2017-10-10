#include <SFML/Window/Event.hpp>

#include "play_scene.h"
#include "game_constants.h"

/**
 * Constructs the PlayScene and attaches the render window and scene manager to it.
 * @param window The Render Window that the scene will be drawn to.
 * @param sceneManager The Scene Manager that manages this scene.
 */
PlayScene::PlayScene(sf::RenderWindow &window, SceneManager &sceneManager)
: Scene{window, sceneManager}
, player_{{(game::SCREEN_WIDTH / 2) + 16, game::SCREEN_HEIGHT - 66}}
, score_{0}
{
    font_.loadFromFile(asset::GAME_FONT);
    scoreText_.setPosition(game::SCREEN_WIDTH - 100, 5);
    scoreText_.setFont(font_);
    scoreText_.setFillColor(sf::Color::Black);
    scoreText_.setStyle(sf::Text::Regular);
    scoreText_.setCharacterSize(72);
    background_.setTexture(resources_.loadTexture(asset::PLAY_BG));
    resources_.load(player_);

    Apple apple{{32, 0}};
    resources_.load(apple);

    spawner_.attachPrototype(apple);
}

/**
 * Handles user interaction with the Scene.
 */
void PlayScene::interact()
{
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            shouldExit(true);
        }
    }
}

/**
 * Updates the Scene's game objects.
 * @param elapsed The elapsed time for this game loop iteration.
 */
void PlayScene::update(float elapsed)
{
    if (spawner_.isSpawnCollidingWith(player_)) {
        ++score_;
    }

    spawner_.update(elapsed);
    player_.update(elapsed);
    scoreText_.setString(std::to_string(score_));
}

/**
 * Draws the visual game objects to the window.
 */
void PlayScene::draw()
{
    window_.clear();
    window_.draw(background_);
    window_.draw(spawner_);
    window_.draw(player_);
    window_.draw(scoreText_);
    window_.display();
}

