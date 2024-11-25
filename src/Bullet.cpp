#include <iostream>

#include "../include/Bullet.hpp"

Bullet::Bullet()
{
    if(!textureLoaded)
    {
        loadTextures();
    }

    bullet.setPosition(sf::Vector2f(10, 10));
}

void Bullet::loadTextures()
{
    if(!bulletTexture.loadFromFile("assets/bullet.png"))
    {
        std::cerr << "I can't load a bullet\n";
    }
    bullet.setTexture(bulletTexture);

    textureLoaded = true;
}
void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(bullet);
}
void Bullet::move()
{
    bullet.move(0.f, -bulletSpeed);
}
