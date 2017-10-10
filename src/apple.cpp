#include <SFML/Graphics/RenderTarget.hpp>
#include "engine/resources.h"
#include "apple.h"
#include "game_constants.h"

/**
 * Constructs the Apple at the provided location and assigns it an optional speed value.
 * @param position The Apple's initial position.
 * @param speed The Apple's initial speed.
 */
Apple::Apple(sf::Vector2f position, float speed)
: GameObject{{32, 32}, position}
, speed_{speed}
, shouldBeDestroyed_{false}
{

}

/**
 * Creates a clone of this specific apple. This method is used primarily by the Spawner so the Apples may simply be
 * copied and modified rather than reloaded from scratch.
 * @param position The location to clone the Apple to.
 * @return The new Apple clone.
 */
Apple Apple::clone(sf::Vector2f position) const
{
    Apple newApple = *this;
    newApple.lifespan_.restart();
    newApple.setPosition(position);
    return newApple;
}

/**
 * @return The duration the Apple has been alive.
 */
sf::Time Apple::lifeTime() const
{
    return lifespan_.getElapsedTime();
}

/**
 * @return True if the Apple should be destroyed, false if not.
 */
bool Apple::isDead() const
{
    return shouldBeDestroyed_;
}

/**
 * Marks this Apple as destructable.
 */
void Apple::die()
{
    shouldBeDestroyed_ = true;
}

/**
 * Updates the Apple's state.
 * @param elapsed The elapsed time for this game loop iteration.
 */
void Apple::update(float elapsed)
{
    move({0, 1}, elapsed * speed_);
    sprite_.setPosition(position());
    shouldBeDestroyed_ = shouldBeDestroyed_ ||
            position().y > game::SCREEN_HEIGHT + size().y ||
            lifeTime().asSeconds() >= LIFESPAN;
}

/**
 * Loads the Apple.
 * @param resources The Scene's resources object.
 */
void Apple::load(Resources &resources)
{
    sprite_.setTexture(resources.loadTexture(asset::APPLE));
}

/**
 * Draws the Apple.
 */
void Apple::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_);
}
