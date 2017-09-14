#ifndef ORCHARD_PLAY_SCENE_H
#define ORCHARD_PLAY_SCENE_H

#include "engine/scene.h"

class PlayScene : public Scene
{
    public:
        explicit PlayScene(sf::RenderWindow& window);
        ~PlayScene() override = default;

        void interact() override;
        void update(float elapsed) override;
        void draw() override;
};

#endif // ORCHARD_PLAY_SCENE_H

