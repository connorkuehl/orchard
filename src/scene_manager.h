#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

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

#endif // SCENE_MANAGER_H_
