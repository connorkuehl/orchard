#ifndef ORCHARD_RESOURCES_H
#define ORCHARD_RESOURCES_H

#include <map>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "iloadable.h"

class Resources
{
    public:
        void load(ILoadable &loadable);
        sf::Texture& loadTexture(const std::string &filePath);
    private:
        std::map<std::string, sf::Texture> textures_;
};

#endif //ORCHARD_RESOURCES_H
