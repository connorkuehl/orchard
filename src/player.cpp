#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "engine/resources.h"
#include "player.h"
#include "game_constants.h"

/**
 * Constructs the Player at the given location.
 * @param position The initial position for the Player.
 */
Player::Player(sf::Vector2f position)
: GameObject{PLAYER_SIZE, position}
{
}

/**
 * Handles user interaction for the Player.
 * @param elapsed The elapsed time for this iteration of the game loop.
 */
void Player::interact(float elapsed)
{
    auto delta = PLAYER_SPEED * elapsed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move({-1, 0}, delta);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move({1, 0}, delta);
    }
}

/**
 * Updates the Player's state.
 * @param elapsed The elapsed time for this iteration of the game loop.
 */
void Player::update(float elapsed)
{
    interact(elapsed);
    sprite_.setPosition(position().x, position().y);

}

/**
 * Loads the Player's assets.
 * @param resources The Resources object dedicated to the scene.
 */
void Player::load(Resources &resources)
{
    auto &tex = resources.loadTexture(asset::PLAYER_BASKET);
    sprite_.setTexture(tex);
}

/**
 * Draws the Player to the window.
 */
void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_, states);
}
