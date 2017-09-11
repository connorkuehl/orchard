#ifndef SCENE_H_
#define SCENE_H_

#include "renderer.h"

class Scene 
{
    public:
        Scene(Renderer& renderer);
        virtual ~Scene();

        virtual void interact() = 0;
        virtual void update(Uint32 elapsed) = 0;
        virtual void draw() = 0;
        bool isExiting() const;
    protected:
        void shouldExit(bool value);
    private:
        Renderer& renderer_;
        bool isExiting_;
};

#endif // SCENE_H_

