#include "scene_manager.h"

SceneManager::SceneManager() {}

void SceneManager::push(Scene* newScene, bool isReplacing)
{
    if (isReplacing) {
        pop();
    }

    scenes_.push(std::unique_ptr<Scene>(newScene));
}

void SceneManager::pop()
{
    if (hasScenes()) {
        scenes_.pop();
    }
}

Scene* SceneManager::top() const
{
    if (!hasScenes()) {
        return nullptr;
    }
    return scenes_.top().get();
}

bool SceneManager::hasScenes() const
{
    return !scenes_.empty();
}

