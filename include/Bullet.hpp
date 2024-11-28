#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Sprite bullet;

    float bulletSpeed = 7.f;
public:
    Bullet();

    void draw(sf::RenderWindow& window) const;

    void moveBullet();
    void setPos(float x, float y);

    float getPosX() const;
    float getPosY() const;
    float getSpeed() const;

    bool isOffScreen();

    const sf::Sprite& getSprite() const;
};
