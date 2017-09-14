#include <SFML/Graphics/RenderTarget.hpp>
#include "engine/resources.h"
#include "apple.h"

Apple::Apple(sf::Vector2f position)
: GameObject{{32, 32}, position}
{

}

void Apple::update(float elapsed)
{
    move({0, -1}, elapsed * SPEED);
}

void Apple::load(Resources &resources)
{
    sprite_.setTexture(resources.loadTexture("res/apple.png"));
}

void Apple::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_);
}
