#include <iostream>

#include "../include/Bullet.hpp"

Bullet::Bullet() : bullet{std::make_unique<sf::Sprite>()}
{
    if(!textureLoaded)
    {
        loadTextures();
    }
}

void Bullet::loadTextures()
{
    if(!bulletTexture.loadFromFile("../assets/bullet.png"))
    {
        std::cerr << "I can't load a bullet\n";
    }
    bullet->setTexture(bulletTexture);

    textureLoaded = true;
}

void Bullet::draw(sf::RenderWindow& window) const
{
    window.draw(*bullet);
}

void Bullet::moveBullet()
{
    bullet->move(0.f, -bulletSpeed);
}

void Bullet::setPos(float x, float y)
{
    bullet->setPosition(sf::Vector2f(x, y));
}

float Bullet::getSpeed() const
{
    return bulletSpeed;
}
