#ifndef ORCHARD_APPLE_H
#define ORCHARD_APPLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "engine/game_object.h"
#include "engine/iloadable.h"

namespace
{
    const auto SPEED = 500.f;
}

class Apple
: public GameObject
, public virtual sf::Drawable
, public virtual ILoadable
{
    public:
        Apple(sf::Vector2f position);

        void update(float elapsed) override;
        void load(Resources &resources) override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    private:
        sf::Sprite sprite_;
};

#endif //ORCHARD_APPLE_H
