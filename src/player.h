#ifndef ORCHARD_PLAYER_H
#define ORCHARD_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>

#include "engine/iloadable.h"
#include "engine/game_object.h"

namespace
{
    const auto PLAYER_SPEED = 400.f;
    const sf::Vector2f PLAYER_SIZE = {32, 64};
}

/**
 * @brief The Player object manages Player state, interaction, and visual aspects.
 */
class Player
: public GameObject
, public virtual sf::Drawable
, public virtual ILoadable
{
    public:
        /// @brief Constructs a Player at the specified position.
        explicit Player(sf::Vector2f position);

        /// @brief Handles player input.
        void interact(float elapsed);
        /// @brief Updates Player state.
        void update(float elapsed) override;
        /// @brief Loads the Player resources.
        void load(Resources &resources) override;
        /// @brief Draws the Player.
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
        sf::Sprite sprite_; ///< The Player's sprite.
};

#endif //ORCHARD_PLAYER_H
