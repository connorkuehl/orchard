#ifndef ORCHARD_SCENE_H
#define ORCHARD_SCENE_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "resources.h"

class SceneManager;

class Scene
{
    public:
        Scene(sf::RenderWindow &window, SceneManager & sceneManager);
        virtual ~Scene();

        virtual void interact() = 0;
        virtual void update(float elapsed) = 0;
        virtual void draw() = 0;
        bool isExiting() const;
    protected:
        sf::RenderWindow &window_;
        Resources resources_;
        SceneManager & sceneManager_;

        void shouldExit(bool value);
    private:
        bool isExiting_;
};

#endif // ORCHARD_SCENE_H
