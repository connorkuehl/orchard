#include <SFML/Graphics/RenderTarget.hpp>
#include "engine/resources.h"
#include "apple.h"
#include "game_constants.h"

Apple::Apple(sf::Vector2f position, float speed)
: GameObject{{32, 32}, position}
, speed_{speed}
{

}

Apple Apple::clone(sf::Vector2f position) const
{
    Apple newApple = *this;
    // Clamp the Apples onto the screen, because the 'x' coordinate
    // originates at the bottom left corner, they could accidentally
    // clip off the right.
    if (position.x > game::SCREEN_WIDTH - size().x) {
        position.x = game::SCREEN_WIDTH - size().x;
    }
    newApple.setPosition(position);
    return newApple;
}

sf::Time Apple::lifeTime() const
{
    return lifespan_.getElapsedTime();
}

bool Apple::isDead() const
{
    return position().y > game::SCREEN_HEIGHT + size().y || lifeTime().asSeconds() >= LIFESPAN;
}

void Apple::update(float elapsed)
{
    move({0, 1}, elapsed * speed_);
    sprite_.setPosition(position());
}

void Apple::load(Resources &resources)
{
    sprite_.setTexture(resources.loadTexture("res/apple.png"));
}

void Apple::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_);
}
