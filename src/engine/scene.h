#ifndef ORCHARD_SCENE_H
#define ORCHARD_SCENE_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "resources.h"

class SceneManager;

/**
 * @brief The Scene abstract base class describes the functionality of a Scene.
 */
class Scene
{
    public:
        /// @brief Constructs the Scene and attaches the render window and scene manager to it.
        Scene(sf::RenderWindow &window, SceneManager &sceneManager);
        virtual ~Scene() = default;

        /// @brief Handles user interaction.
        virtual void interact() = 0;
        /// @brief Updates the Scene based on game logic in this method's implementation.
        virtual void update(float elapsed) = 0;
        /// @brief Draws all visual GameObjects to the screen.
        virtual void draw() = 0;
        /// @brief Queries if the Scene is in an exiting state.
        bool isExiting() const;
    protected:
        sf::RenderWindow &window_; ///< The RenderWindow -- this is required for drawing to the window.
        Resources resources_; ///< The resources that the scene requires.
        SceneManager &sceneManager_; ///< The reference to a scene manager for adding intermediate states.

        void shouldExit(bool value); ///< Sets (or unsets) the Scene to an exiting state.
    private:
        bool isExiting_; ///< Is the Scene exiting?
};

#endif // ORCHARD_SCENE_H
