#include <random>
#include <algorithm>
#include <SFML/Graphics/RenderTarget.hpp>
#include "game_constants.h"
#include "spawner.h"

Spawner::Spawner(float initialSpawnDelay)
: prototype_{{0, 0}}
, spawnDelay_{initialSpawnDelay}
{
}

void Spawner::attachPrototype(Apple &prototype)
{
    prototype_ = prototype;
}

bool Spawner::isSpawnCollidingWith(const GameObject &other){
    bool colliding = false;
    for (auto& apple : apples_) {
        if (apple.isCollidingWith(other)) {
            apple.die();
            colliding = true;
        }
    }
    return colliding;
}

void Spawner::update(float elapsed)
{
    if (timer_.getElapsedTime().asSeconds() >= spawnDelay_) {
        spawn();
        timer_.restart();
    }

    for (auto &apple : apples_) {
        apple.update(elapsed);
    }

    apples_.erase(std::remove_if(apples_.begin(), apples_.end(),
    [](const auto &apple) {
        return apple.isDead();
    }), apples_.end());
}

void Spawner::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto &apple : apples_) {
        target.draw(apple);
    }
}

void Spawner::spawn()
{
    apples_.emplace_back(prototype_.clone(randomPosition()));
}

sf::Vector2f Spawner::randomPosition() const
{
    static std::default_random_engine engine{};
    static std::uniform_real_distribution<float> range{0, game::SCREEN_WIDTH - 32};
    return {range(engine), 0.f};
}
