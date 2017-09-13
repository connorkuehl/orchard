#include "game_object.h"

GameObject::GameObject(sf::Vector2i size, sf::Vector2i position)
: size_{size}
, position_{position}
{
}

void GameObject::move(sf::Vector2i direction, sf::Uint32 delta)
{
    position_.x = direction.x * delta;
    position_.y = direction.y * delta;
}

const sf::Vector2i &GameObject::position() const
{
    return position_;
}
