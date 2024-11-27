#include <iostream>

#include "../include/Enemy.hpp"
#include "../include/LoadedTextures.hpp"
#include "../include/constants.h"

Enemy::Enemy()
{
    UFO.setTexture(*(textures.getTexture(3)));
    UFO.setPosition(10, 10);
    UFO.setScale(0.65f, 0.65f);
}

void Enemy::draw(sf::RenderWindow &window)
{
    window.draw(UFO);
}

float Enemy::getPosX() const
{
    return UFO.getPosition().x;
}

float Enemy::getPosY() const
{
    return UFO.getPosition().y;
}

float Enemy::getSpeed() const
{
    return speedUFO;
}

void Enemy::move()
{
    UFO.move(speedUFO, 0.f);
    if(UFO.getPosition().x >= Constants::Resolution::weight - Constants::Enemy::UFO::UxSize)
    {
        speedUFO = -5.f;
    }
    if(UFO.getPosition().x <= 0)
    {
        speedUFO = 5.f;
    }
}
