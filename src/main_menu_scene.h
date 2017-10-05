#ifndef MAIN_MENU_SCENE_H_
#define MAIN_MENU_SCENE_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "engine/scene.h"

class MainMenuScene : public Scene
{
    public:
        explicit MainMenuScene(sf::RenderWindow &window, SceneManager &sceneManager);
        ~MainMenuScene() override = default;

        void interact() override;
        void update(float elapsed) override;
        void draw() override;
    private:
        sf::Sprite mainMenu_;
};

#endif // MAIN_MENU_SCENE_H_
