#ifndef ORCHARD_GAME_OBJECT_H_H
#define ORCHARD_GAME_OBJECT_H_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

class GameObject
{
    public:
        GameObject(sf::Vector2 &size = {0, 0}, sf::Vector2 &position = {0, 0});
        virtual ~GameObject() = default;

        virtual void update(sf::Time &elapsed) = 0;
    protected:
        void move(sf::Vector2 &direction, sf::Uint32 delta);
    private:
        sf::Vector2 size_;
        sf::Vector2 position_;
};

#endif //ORCHARD_GAME_OBJECT_H_H
