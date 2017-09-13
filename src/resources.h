#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <map>
#include <string>

#include "SDL.h"

#include "iloadable.h"

class Resources
{
    public:
        Resources(SDL_Renderer& renderer);
       ~Resources();

       void load(ILoadable& loadable);
       SDL_Texture* loadTexture(const std::string& filePath);
    private:
       SDL_Renderer* renderer_;
       std::map<std::string, SDL_Texture*> textures_;
};

#endif // RESOURCES_H_

