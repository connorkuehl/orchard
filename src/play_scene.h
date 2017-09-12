#ifndef PLAY_SCENE_H_
#define PLAY_SCENE_H_

#include "scene.h"

class PlayScene : public Scene
{
    public:
        PlayScene(Renderer& renderer);
       ~PlayScene();

       void interact();
       void update(Uint32 elapsed);
       void draw();
    private:
};

#endif // PLAY_SCENE_H_
