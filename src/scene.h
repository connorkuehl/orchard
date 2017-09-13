#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
    public:
        Scene(sf::RenderWindow& window);
        virtual ~Scene();

        virtual void interact() = 0;
        virtual void update(sf::Time &elapsed) = 0;
        virtual void draw() = 0;
        bool isExiting() const;
    protected:
        sf::RenderWindow& window_;

        void shouldExit(bool value);
    private:
        bool isExiting_;
};

#endif // SCENE_H_
