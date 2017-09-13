#ifndef ORCHARD_PLAYER_H
#define ORCHARD_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>

#include "iloadable.h"
#include "game_object.h"

class Player
: public GameObject
, public virtual sf::Drawable
, public virtual ILoadable
{
    public:
        Player(sf::Vector2i position);

        void interact();
        void update(sf::Time &elapsed) override;
        void load(Resources &resources) override;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
        sf::Sprite sprite_;
};

#endif //ORCHARD_PLAYER_H
