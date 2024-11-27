#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Sprite UFO;
    float speedUFO = 5.f;
public:
    Enemy();

    void draw(sf::RenderWindow& window);
    float getPosX() const;
    float getPosY() const;
    float getSpeed() const;
    void move();
};
