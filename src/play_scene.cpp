#include "play_scene.h"

PlayScene::PlayScene(Renderer& renderer)
: Scene{renderer}
, mySprite_{32, 32}
{
    mySprite_.setImage(resources_.loadTexture("res/characters.png"),
            0, 32);
}

PlayScene::~PlayScene()
{
}


void PlayScene::interact()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            shouldExit(true);
        }
    }
}

void PlayScene::update(Uint32 elapsed)
{
}

void PlayScene::draw()
{
    renderer_.clear();
    renderer_.draw(mySprite_);
    renderer_.show();
}

