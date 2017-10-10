#ifndef ORCHARD_APPLE_H
#define ORCHARD_APPLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "engine/game_object.h"
#include "engine/iloadable.h"

namespace
{
    const auto APPLE_SPEED = 500.f;
    const auto LIFESPAN = 8.f;
}

/**
 * @brief The Apple class represents an Apple in the game.
 */
class Apple
: public GameObject
, public virtual sf::Drawable
, public virtual ILoadable
{
    public:
        /// @brief Creates an Apple at an initial position with an optional speed argument.
        explicit Apple(sf::Vector2f position, float speed = APPLE_SPEED);

        /// @brief Creates an identical Apple (same texture, speed, etc), but at a different position.
        Apple clone(sf::Vector2f position) const;
        /// @brief Queries if this specific Apple is dead (collected or off-screen, etc).
        bool isDead() const;
        /// @brief Sets the boolean to true so that this object is destroyed.
        void die();
        /// @brief Updates the Apple's state.
        void update(float elapsed) override;
        /// @brief Tells the Resources object how to load the Apple.
        void load(Resources &resources) override;
        /// @brief Draws the Apple to the screen.
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    protected:
        /// @brief Returns how long the Apple has been alive.
        sf::Time lifeTime() const;
    private:
        sf::Sprite sprite_; ///< The Apple's Sprite.
        sf::Clock lifespan_; ///< The Apple's age.
        float speed_; ///< How fast the Apple should fall.
        bool shouldBeDestroyed_; ///< Should this Apple be destroyed?
};

#endif //ORCHARD_APPLE_H
