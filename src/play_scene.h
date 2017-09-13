#ifndef ORCHARD_PLAY_SCENE_H
#define ORCHARD_PLAY_SCENE_H

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

#endif // ORCHARD_PLAY_SCENE_H

