#include "resources.h"

/**
 * Loads the game object by invoking its load() method.
 * @param loadable The object to load.
 */
void Resources::load(ILoadable &loadable)
{
    loadable.load(*this);
}

/**
 * Loads the texture at the specified file path.
 * @param filePath The path to the texture.
 * @return The loaded texture.
 */
sf::Texture& Resources::loadTexture(const std::string &filePath)
{
    auto exists = textures_.find(filePath);
    if (exists != textures_.end()) {
        return exists->second;
    }

    sf::Texture tex;
    tex.loadFromFile(filePath);
    auto texture = textures_.insert(std::make_pair(filePath, tex));
    return texture.first->second;
}
