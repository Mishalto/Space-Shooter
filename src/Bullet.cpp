#include <iostream>

#include "../include/Bullet.hpp"
#include "../include/LoadedTextures.hpp"

Bullet::Bullet()
{
    bullet.setTexture(*(textures.getTexture(2)));
}

void Bullet::draw(sf::RenderWindow& window) const
{
    window.draw(bullet);
}

void Bullet::moveBullet()
{
    bullet.move(0.f, -bulletSpeed);
}

void Bullet::setPos(float x, float y)
{
    bullet.setPosition(sf::Vector2f(x, y));
}

float Bullet::getSpeed() const
{
    return bulletSpeed;
}

bool Bullet::isOffScreen()
{
    return bullet.getPosition().y < 0;
}

float Bullet::getPosY() const
{
    return bullet.getPosition().y;
}

float Bullet::getPosX() const
{
    return bullet.getPosition().x;
}

const sf::Sprite& Bullet::getSprite() const
{
    return bullet;
}
