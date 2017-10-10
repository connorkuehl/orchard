#ifndef ORCHARD_GAME_OBJECT_H_H
#define ORCHARD_GAME_OBJECT_H_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>

/**
 * @brief The GameObject class represents an object that can be displayed
 * in game.
 */
class GameObject
{
    public:
        /// @brief Constructs a GameObject with a size and position.
        GameObject(sf::Vector2f size, sf::Vector2f position);
        virtual ~GameObject() = default;

        /// @brief Updates the GameObject based on the game logic in this method.
        virtual void update(float elapsed) = 0;
        /// @brief Determines if this object is currently colliding with another GameObject.
        virtual bool isCollidingWith(const GameObject &other) const;
    protected:
        /// @brief Moves the object.
        void move(sf::Vector2f direction, float delta);
        /// @brief Sets the object's position.
        void setPosition(sf::Vector2f position);
        /// @brief Get the current position.
        const sf::Vector2f &position() const;
        /// @brief Get the current size.
        const sf::Vector2f &size() const;
    private:
        sf::Vector2f size_; ///< The size of the GameObject.
        sf::Vector2f position_; ///< The x, y coordinates of the GameObject's bottom-left corner.
        sf::FloatRect collider_; ///< The bounding box used for detecting collisions (intersections).
};

#endif //ORCHARD_GAME_OBJECT_H_H
