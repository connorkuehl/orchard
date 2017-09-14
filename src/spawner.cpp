#include <random>
#include <algorithm>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
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

void Spawner::update(float elapsed)
{
    if (timer_.getElapsedTime().asSeconds() >= spawnDelay_) {
        spawn();
        timer_.restart();
    }

    for (auto& apple : apples_) {
        apple.update(elapsed);
    }

    std::remove_if(apples_.begin(), apples_.end(),
    [](const auto &apple) {
        return apple.isDead();
    });
}

void Spawner::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto& apple : apples_) {
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
    static std::uniform_real_distribution<float> range{0, game::SCREEN_WIDTH};
    return {range(engine), 0.f};
}
