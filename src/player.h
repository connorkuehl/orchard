#ifndef ORCHARD_PLAYER_H
#define ORCHARD_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>

#include "engine/iloadable.h"
#include "engine/game_object.h"

namespace
{
    const auto SPEED = 350.f;
}

class Player
: public GameObject
, public virtual sf::Drawable
, public virtual ILoadable
{
    public:
        Player(sf::Vector2f position);

        void interact(float elapsed);
        void update(float elapsed) override;
        void load(Resources &resources) override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
        sf::Sprite sprite_;
};

#endif //ORCHARD_PLAYER_H
