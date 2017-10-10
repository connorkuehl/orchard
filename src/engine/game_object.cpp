#include <iostream>

#include "game_object.h"

/**
 * Constructs a GameObject with the given size at the given location.
 * @param size The size of the object.
 * @param position The initial position of the object.
 */
GameObject::GameObject(sf::Vector2f size, sf::Vector2f position)
: size_{size}
, position_{position}
, collider_{position, size}
{
}

/**
 * Queries if this current object is colliding with the other.
 * @param other The other game object it could be colliding with.
 * @return
 */
bool GameObject::isCollidingWith(const GameObject &other) const
{
    return collider_.intersects(other.collider_);
}

/**
 * Moves the game object in the specified direction with the specified delta.
 * @param direction The direction the game object should move.
 * @param delta The amount the game object should move.
 */
void GameObject::move(sf::Vector2f direction, float delta)
{
    position_.x += direction.x * delta;
    position_.y += direction.y * delta;
    collider_.top = position_.y;
    collider_.left = position_.x;
}

/**
 * Sets the game object's absolute position.
 * @param position The new position the game object should take.
 */
void GameObject::setPosition(sf::Vector2f position)
{
    position_ = position;
}

/**
 * @return The game object's position.
 */
const sf::Vector2f &GameObject::position() const
{
    return position_;
}

/**
 * @return The game object's size.
 */
const sf::Vector2f &GameObject::size() const
{
    return size_;
}
