#include <iostream>

#include "../include/Spaceship.hpp"
#include "../include/constants.h"

Spaceship::Spaceship()
{
    if(!textureLoaded)
    {
        loadTextures();
    }
    spaceship.setPosition(sf::Vector2f(Constants::weight / 2 - Constants::Spaceship::xSize, Constants::height - Constants::Spaceship::ySize));
}

void Spaceship::loadTextures()
{
    if (!spaceshipTexture.loadFromFile("assets/spaceship.png"))
    {
        std::cerr << "I can't load a spaceship\n";
    }
    spaceship.setTexture(spaceshipTexture);

    textureLoaded = true;
}

void Spaceship::management()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        spaceship.move(shipSpeed, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        spaceship.move(-shipSpeed, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spaceship.move(0.f, shipSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        spaceship.move(0.f, -shipSpeed);
    }
}

void Spaceship::update()
{
    management();
}

void Spaceship::draw(sf::RenderWindow& window)
{
    window.draw(spaceship);
}
