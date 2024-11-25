#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Texture bulletTexture;
    sf::Sprite bullet;

    const float bulletSpeed = 5.f;

    bool textureLoaded = false;

public:
    Bullet();

    void loadTextures();
    void draw(sf::RenderWindow& window) const;
    void moveBullet();
    void setPos(float x, float y);

    float getSpeed() const;
};
