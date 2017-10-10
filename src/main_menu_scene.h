#ifndef MAIN_MENU_SCENE_H_
#define MAIN_MENU_SCENE_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "engine/scene.h"

/**
 * @brief The MainMenuScene is the initial scene when the game starts. It prompts the user to play.
 */

class MainMenuScene : public Scene
{
    public:
        /// @brief Constructs the MainMenuScene and attaches the RenderWindow and SceneManager to it.
        explicit MainMenuScene(sf::RenderWindow &window, SceneManager &sceneManager);
        ~MainMenuScene() override = default;

        /// @brief Listens for user input to transition to a play state.
        void interact() override;
        /// @brief Does nothing.
        void update(float elapsed) override;
        /// @brief Draws the main menu image to the screen.
        void draw() override;
    private:
        sf::Sprite mainMenu_; ///< The image to display as the main menu.
};

#endif // MAIN_MENU_SCENE_H_
