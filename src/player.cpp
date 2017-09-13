#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "resources.h"
#include "player.h"

Player::Player(sf::Vector2i position)
: GameObject{{32, 32}, position}
{
}

void Player::interact()
{

}

void Player::update(sf::Time &elapsed)
{

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
