#include "scene.h"

/**
 * Constructs the Scene, attaching the render window and scene manager to it for easy access in derived scenes.
 * @param window The window that the scene will be drawn to.
 * @param sceneManager The scene manager that the scene belongs to.
 */
Scene::Scene(sf::RenderWindow& window, SceneManager &sceneManager)
: window_{window}
, sceneManager_{sceneManager}
, isExiting_{false}
{
}

/**
 * @return A boolean describing if the scene be destroyed or not.
 */
bool Scene::isExiting() const
{
    return isExiting_;
}

/**
 * Allows for derived scenes to request an exit.
 * @param value True, if the scene wants to exit. False, if the scene wants to cancel the exit.
 */
void Scene::shouldExit(bool value)
{
    isExiting_ = value;
}
