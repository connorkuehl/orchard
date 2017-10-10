#include "scene_manager.h"

/**
 * Constructs the SceneManager in an empty state.
 */
SceneManager::SceneManager()
: transition_{nullptr}
, transitionReplacing_{false}
{
}

/**
 * Places a new state in the "awaiting" position so the next game loop will transition.
 * @param newScene The scene to transition to.
 * @param isReplacing Whether or not the scene should REPLACE the current one or just go on top of it.
 */
void SceneManager::transition(std::unique_ptr<Scene> newScene, bool isReplacing)
{
    transition_ = std::move(newScene);
    transitionReplacing_ = isReplacing;
}

/**
 * Makes the transition.
 */
void SceneManager::makeTransition()
{
    if (transition_ != nullptr) {
        push();
    }
}

/**
 * Pushes the awaiting state onto the stop of the stack.
 */
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

/**
 * Removes the current scene from the stack.
 */
void SceneManager::pop()
{
    if (hasScenes()) {
        scenes_.pop();
    }
}

/**
 * @return The currently executing state, if there is one.
 */
Scene *SceneManager::top() const
{
    if (!hasScenes()) {
        return nullptr;
    }
    return scenes_.top().get();
}

/**
 * @return True if the SceneManager has states to execute, false if it does not.
 */
bool SceneManager::hasScenes() const
{
    return !scenes_.empty();
}

/**
 * @return True if the SceneManager has a Scene waiting to be transitioned to, false if it does not.
 */
bool SceneManager::awaitingTransition() const
{
    return transition_ != nullptr;
}

