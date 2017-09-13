#ifndef SCENE_H_
#define SCENE_H_

#include "renderer.h"
#include "resources.h"

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
        Renderer& renderer_;
        Resources resources_;

        void shouldExit(bool value);
    private:
        bool isExiting_;
};

#endif // SCENE_H_

