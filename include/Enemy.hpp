#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Sprite UFO;
    float speedUFO = 5.f;
    int health = 5;

public:
    Enemy();

    void draw(sf::RenderWindow& window);
    float getPosX() const;
    float getPosY() const;
    float getSpeed() const;
    void move();
    void reduceHealth();
    bool isAlive();
    const sf::Sprite& getTexture() const;
};
