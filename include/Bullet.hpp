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
    void draw(sf::RenderWindow& window);
    void move();
};
