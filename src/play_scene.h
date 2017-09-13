#ifndef PLAY_SCENE_H_
#define PLAY_SCENE_H_

#include "scene.h"

class PlayScene : public Scene
{
    public:
        PlayScene(sf::RenderWindow& window);
       ~PlayScene();

       void interact();
       void update(sf::Time &elapsed);
       void draw();
    private:
};

#endif // PLAY_SCENE_H_

