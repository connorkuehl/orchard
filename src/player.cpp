#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "resources.h"
#include "player.h"

Player::Player(sf::Vector2f position)
: GameObject{{32, 32}, position}
{
}

void Player::interact(float elapsed)
{
    auto delta = SPEED * elapsed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move({-1, 0}, delta);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move({1, 0}, delta);
    }
}

void Player::update(float elapsed)
{
    interact(elapsed);
    sprite_.setPosition(position().x, position().y);

}

void Player::load(Resources &resources)
{
    auto& tex = resources.loadTexture("res/apple.png");
    sprite_.setTexture(tex);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_, states);
}
