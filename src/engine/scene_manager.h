#ifndef ORCHARD_SCENE_MANAGER_H
#define ORCHARD_SCENE_MANAGER_H

#include <memory>
#include <stack>

#include "scene.h"

/**
 * @brief The SceneManager is a pushdown automata (state machine) for managing game states.
 */
class SceneManager
{
    public:
        SceneManager();
        ~SceneManager() = default;
        /// @brief Transitions to the next Scene if there is one waiting.
        void makeTransition();
        /// @brief Provides a Scene to transition to next.
        void transition(std::unique_ptr<Scene> newScene, bool isReplacing = true);
        /// @brief Destroys the currently executing scene (i.e., when it's exiting).
        void pop();
        /// @brief Provides a pointer to the current scene.
        Scene* top() const;
        /// @brief Queries if there are any scenes.
        bool hasScenes() const;
        /// @brief Queries if there is a Scene that we are waiting to transition to.
        bool awaitingTransition() const;
    protected:
        /// @brief Make the waiting scene the current scene by pushing it to the top of the stack.
        void push();
    private:
        std::stack<std::unique_ptr<Scene>> scenes_; ///< All of the currently managed scenes.
        std::unique_ptr<Scene> transition_; ///< The waiting Scene that should be ran next.
        bool transitionReplacing_; ///< Should the transition REPLACE the current scene or just run on top of it?
};

#endif // ORCHARD_SCENE_MANAGER_H
