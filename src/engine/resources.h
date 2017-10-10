#ifndef ORCHARD_RESOURCES_H
#define ORCHARD_RESOURCES_H

#include <map>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "iloadable.h"

/**
 * @brief The Resources class is responsible for loading, distributing, and managing the lifetime of game assets.
 */
class Resources
{
    public:
        /// @brief Loads the loadable object.
        void load(ILoadable &loadable);
        /// @brief Loads the texture at the given file location.
        sf::Texture& loadTexture(const std::string &filePath);
    private:
        std::map<std::string, sf::Texture> textures_; ///< Contains all of the loaded textures.
};

#endif //ORCHARD_RESOURCES_H
