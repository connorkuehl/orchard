#ifndef ORCHARD_SPAWNER_H
#define ORCHARD_SPAWNER_H

#include <vector>
#include "apple.h"

namespace
{
    const auto APPLES_PER_SECOND = 2.f;
}

class Spawner
{
    public:
        Spawner();
        void update();
    private:
        sf::Clock timer_;
        std::vector<Apple> apples_;
        int spawnedThisSecond_;

        void spawn();
};

#endif //ORCHARD_SPAWNER_H
