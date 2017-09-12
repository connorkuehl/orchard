#include "play_scene.h"
#include "game.h"

Game::Game(const std::string& name, size_t width, size_t height)
: window_{width, height, name}
, isRunning_ { true }
{
    renderer_.attachToWindow(window_.get());
}

void Game::run()
{
    sceneManager_.push(new PlayScene(renderer_));
    
    auto last = SDL_GetTicks();
    while (sceneManager_.hasScenes()) {
        auto now = SDL_GetTicks();
        auto elapsed = now - last;
        last = now;

        auto currentScene = sceneManager_.top();

        currentScene->interact();
        currentScene->update(elapsed);
        currentScene->draw();

        if (currentScene->isExiting()) {
            sceneManager_.pop();
        }
    }
}

