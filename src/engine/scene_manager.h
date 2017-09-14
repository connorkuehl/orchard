#ifndef ORCHARD_SCENE_MANAGER_H
#define ORCHARD_SCENE_MANAGER_H

#include <memory>
#include <stack>

#include "scene.h"

class SceneManager
{
    public:
        SceneManager();
        void push(Scene* newScene, bool isReplacing = true);
        void pop();
        Scene* top() const;
        bool hasScenes() const;
    private:
        std::stack<std::unique_ptr<Scene>> scenes_;
};

#endif // ORCHARD_SCENE_MANAGER_H
