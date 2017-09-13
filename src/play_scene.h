#ifndef ORCHARD_PLAY_SCENE_H
#define ORCHARD_PLAY_SCENE_H

#include "scene.h"
#include "player.h"

class PlayScene : public Scene
{
    public:
        PlayScene(sf::RenderWindow& window);
       ~PlayScene();

       void interact();
       void update(float elapsed);
       void draw();
    private:
        Player player_;
};

#endif // ORCHARD_PLAY_SCENE_H

