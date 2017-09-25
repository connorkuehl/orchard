#ifndef ORCHARD_PLAY_SCENE_H
#define ORCHARD_PLAY_SCENE_H

#include "engine/scene.h"
#include "spawner.h"
#include "player.h"

class PlayScene : public Scene
{
    public:
        explicit PlayScene(sf::RenderWindow & window, SceneManager & sceneManager);
        ~PlayScene() override = default;

        void interact() override;
        void update(float elapsed) override;
        void draw() override;
    private:
        Spawner spawner_;
        Player player_;
        sf::Sprite background_;
        size_t score_;
};

#endif // ORCHARD_PLAY_SCENE_H

