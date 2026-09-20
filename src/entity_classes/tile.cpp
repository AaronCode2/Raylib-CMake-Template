#include "tile.hpp"

Tile::Tile(Vector2 position, TileType type): 
    Sprite({
        position.x, position.y, 
        (float) Textures::texture[ImageIndex::TILE].GetFrameSize().x, 
        (float) Textures::texture[ImageIndex::TILE].GetFrameSize().y
    }, ImageIndex::TILE)
{

    this->type = type;

    srcRect.x = Textures::texture[ImageIndex::TILE].GetFrameSize().x * (int) type;
}

void Tile::update() {

    draw();
}

void Tile::draw() {

    DrawTextureRec(
        Textures::texture[ImageIndex::TILE].texture,
        srcRect, {object.x, object.y},
        WHITE
    );
}
