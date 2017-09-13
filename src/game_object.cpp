#include "game_object.h"

GameObject::GameObject(sf::Vector2 &size, sf::Vector2 &position)
: size_{size}
, position_{position}
{
}

void GameObject::move(sf::Vector2 &direction, sf::Uint32 delta)
{
    position_ += (direction * delta);
}
