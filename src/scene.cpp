#include "scene.h"

Scene::Scene(Renderer& renderer)
: renderer_ { renderer }
, resources_{*renderer_.get()}
, isExiting_ { false }
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

