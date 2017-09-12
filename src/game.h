#ifndef GAME_H_
#define GAME_H_

#include "sdl_application.h"
#include "window.h"
#include "renderer.h"
#include "scene_manager.h"

namespace
{
    const int DEFAULT_WIDTH = 800;
    const int DEFAULT_HEIGHT = 600;
}

class Game : public SdlApplication
{
    public:
        Game(const std::string& name, size_t width = DEFAULT_WIDTH, 
                size_t height = DEFAULT_HEIGHT);
        void run();
    private:
        Window window_;
        Renderer renderer_;
        SceneManager sceneManager_;
        bool isRunning_;
};

#endif // GAME_H_

