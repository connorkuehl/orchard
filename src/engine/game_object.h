#ifndef ORCHARD_GAME_OBJECT_H_H
#define ORCHARD_GAME_OBJECT_H_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

class GameObject
{
    public:
        GameObject(sf::Vector2f size, sf::Vector2f position);
        virtual ~GameObject() = default;

        virtual void update(float elapsed) = 0;
    protected:
        void move(sf::Vector2f direction, float delta);
        const sf::Vector2f &position() const;
    private:
        sf::Vector2f size_;
        sf::Vector2f position_;
};

#endif //ORCHARD_GAME_OBJECT_H_H
