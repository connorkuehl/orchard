#include "scene.h"

Scene::Scene(sf::RenderWindow& window, SceneManager & sceneManager)
: window_{window}
, sceneManager_{sceneManager}
, isExiting_{false}
{
}

Scene::~Scene() {}

bool Scene::isExiting() const
{
    return isExiting_;
}

void Scene::shouldExit(bool value)
{
    isExiting_ = value;
}
