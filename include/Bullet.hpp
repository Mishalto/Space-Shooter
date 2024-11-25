#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Texture bulletTexture;
    sf::Sprite bullet;

    float bulletSpeed = 7.f;
public:
    Bullet();

    void loadTextures();
    void draw(sf::RenderWindow& window) const;
    void moveBullet();
    void setPos(float x, float y);

    float getSpeed() const;
    bool isOffScreen();
};
