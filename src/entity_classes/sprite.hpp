#pragma once
#include <raylib.h>
#include "../utility/utils.hpp"
#include "../utility/textures.hpp"

class Sprite {

    public:

        Sprite(Rectangle object, Vector2 frame, ImageIndex index);

        void update();

        Rectangle getObject() const { return object; };
        Vector2 getFrame() const { return frame; }; 

        Rectangle object;

        Rectangle getSrcRect() const { return srcRect; };
        
    protected:
        
        Vector2 velocity = {0, 0};
        Rectangle srcRect;
        Vector2 frame;

        void draw(Texture2D image = Textures::texture[ImageIndex::PLAYER].texture);
        void animate(const int frameEnd, const int frameStart = 0, const float frameDuration = 0.1f);

        int currentFrame = 0;
        float elapsedFrame = 0;
};