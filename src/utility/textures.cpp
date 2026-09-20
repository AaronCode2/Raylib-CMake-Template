#include "textures.hpp"

std::map<ImageIndex, TextureData> Textures::texture;

void Textures::loadTextures() {

    texture[ImageIndex::PLAYER] = {

        LoadTexture(IMAGE_PLAYER_PATH),
        IMAGE_PLAYER_MAX_FRAMES
    };

    texture[ImageIndex::TILE] = {

        LoadTexture(IMAGE_TILE_PATH),
        IMAGE_TILE_MAX_FRAMES
    };
}

void Textures::unloadTextures() {

    UnloadTexture(texture[ImageIndex::PLAYER].texture);
    UnloadTexture(texture[ImageIndex::TILE].texture);
}
