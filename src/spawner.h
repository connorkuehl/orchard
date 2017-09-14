#ifndef ORCHARD_SPAWNER_H
#define ORCHARD_SPAWNER_H

#include <vector>
#include "apple.h"

namespace
{
    const auto DEFAULT_SPAWN_DELAY = 1.75f;
}

class Spawner : public sf::Drawable
{
    public:
        Spawner(float initialSpawnDelay = DEFAULT_SPAWN_DELAY);
        void attachPrototype(Apple &prototype);
        void update(float elapsed);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    private:
        Apple prototype_;
        sf::Clock timer_;
        std::vector<Apple> apples_;
        float spawnDelay_;

        void spawn();
        sf::Vector2f randomPosition() const;
};

#endif //ORCHARD_SPAWNER_H
