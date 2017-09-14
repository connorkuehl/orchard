#include <iostream>

#include "game_object.h"

GameObject::GameObject(sf::Vector2f size, sf::Vector2f position)
: size_{size}
, position_{position}
{
}

void GameObject::move(sf::Vector2f direction, float delta)
{
    position_.x += direction.x * delta;
    position_.y += direction.y * delta;
}

void GameObject::setPosition(sf::Vector2f position)
{
    position_ = position;
}

const sf::Vector2f &GameObject::position() const
{
    return position_;
}
