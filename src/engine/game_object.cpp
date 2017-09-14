#include <iostream>

#include "game_object.h"

GameObject::GameObject(sf::Vector2f size, sf::Vector2f position)
: size_{size}
, position_{position}
, collider_{position, size}
{
}

bool GameObject::isCollidingWith(const GameObject &other) const
{
    return collider_.intersects(other.collider_);
}

void GameObject::move(sf::Vector2f direction, float delta)
{
    position_.x += direction.x * delta;
    position_.y += direction.y * delta;
    collider_.top = position_.y;
    collider_.left = position_.x;
}

void GameObject::setPosition(sf::Vector2f position)
{
    position_ = position;
}

const sf::Vector2f &GameObject::position() const
{
    return position_;
}

const sf::Vector2f &GameObject::size() const
{
    return size_;
}
