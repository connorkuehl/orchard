#ifndef ORCHARD_GAME_OBJECT_H_H
#define ORCHARD_GAME_OBJECT_H_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

class GameObject
{
    public:
        GameObject(sf::Vector2i size, sf::Vector2i position);
        virtual ~GameObject() = default;

        virtual void update(sf::Time &elapsed) = 0;
    protected:
        void move(sf::Vector2i direction, sf::Uint32 delta);
        const sf::Vector2i &position() const;
    private:
        sf::Vector2i size_;
        sf::Vector2i position_;
};

#endif //ORCHARD_GAME_OBJECT_H_H
