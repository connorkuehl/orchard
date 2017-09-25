#ifndef ORCHARD_SCENE_MANAGER_H
#define ORCHARD_SCENE_MANAGER_H

#include <memory>
#include <stack>

#include "scene.h"

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager() = default;
        void makeTransition();
        void transition(std::unique_ptr<Scene> newScene, bool isReplacing = true);
        void pop();
        Scene* top() const;
        bool hasScenes() const;
        bool awaitingTransition() const;
    protected:
        void push();
    private:
        std::stack<std::unique_ptr<Scene>> scenes_;
        std::unique_ptr<Scene> transition_;
        bool transitionReplacing_;
};

#endif // ORCHARD_SCENE_MANAGER_H
