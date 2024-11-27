#include <iostream>

#include "../include/Spaceship.hpp"
#include "../include/constants.h"

Spaceship::Spaceship()
{
    if(!textureLoaded)
    {
        loadTextures();
    }
    spaceship.setPosition(sf::Vector2f(Constants::Resolution::weight / 2 - Constants::Spaceship::PxSize, Constants::Resolution::height - Constants::Spaceship::PySize));
}

void Spaceship::loadTextures()
{
    if (!spaceshipTexture.loadFromFile("../assets/spaceship.png"))
    {
        std::cerr << "I can't load a spaceship\n";
    }
    spaceship.setTexture(spaceshipTexture);

    textureLoaded = true;
}

void Spaceship::moveShip(float x, float y)
{
    spaceship.move(x, y);
}

void Spaceship::draw(sf::RenderWindow& window)
{
    window.draw(spaceship);
}

float Spaceship::getSpeed() const
{
    return shipSpeed;
}

float Spaceship::getPosX() const
{
    return spaceship.getPosition().x;
}

float Spaceship::getPosY() const
{
    return spaceship.getPosition().y;
}

