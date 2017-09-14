#ifndef ORCHARD_APPLE_H
#define ORCHARD_APPLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include "engine/game_object.h"
#include "engine/iloadable.h"

namespace
{
    const auto APPLE_SPEED = 500.f;
    const auto LIFESPAN = 8.f;
}

class Apple
: public GameObject
, public virtual sf::Drawable
, public virtual ILoadable
{
    public:
        Apple(sf::Vector2f position, float speed = APPLE_SPEED);

        Apple clone(sf::Vector2f position) const;
        bool isDead() const;
        void update(float elapsed) override;
        void load(Resources &resources) override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    protected:
        sf::Time lifeTime() const;
    private:
        sf::Sprite sprite_;
        sf::Clock lifespan_;
        float speed_;
};

#endif //ORCHARD_APPLE_H
