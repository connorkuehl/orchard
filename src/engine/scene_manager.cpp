#include "scene_manager.h"

SceneManager::SceneManager()
: transition_{nullptr}
, transitionReplacing_{false}
{
}

void SceneManager::transition(std::unique_ptr<Scene> newScene, bool isReplacing)
{
    transition_ = std::move(newScene);
    transitionReplacing_ = isReplacing;
}

void SceneManager::makeTransition()
{
    if (transition_ != nullptr) {
        push();
    }
}

void SceneManager::push()
{
    if (!transition_) {
        return;
    }

    if (transitionReplacing_) {
        pop();
    }

    scenes_.push(std::move(transition_));
    transition_ = nullptr;
    transitionReplacing_ = false;
}

void SceneManager::pop()
{
    if (hasScenes()) {
        scenes_.pop();
    }
}

Scene * SceneManager::top() const
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

bool SceneManager::awaitingTransition() const
{
    return transition_ != nullptr;
}

