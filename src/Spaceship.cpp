#include <iostream>

#include "../include/Spaceship.hpp"
#include "../include/constants.h"

Spaceship::Spaceship()
{
    if(!textureLoaded)
    {
        loadTexture();
    }
    spaceship.setPosition(sf::Vector2f(Constants::weight / 2 - Constants::Spaceship::xSize, Constants::height - Constants::Spaceship::ySize));
}

void Spaceship::loadTexture()
{
    if (!spaceshipTexture.loadFromFile("assets/spaceship.png"))
    {
        std::cerr << "I can't load a spaceship\n";
    }
    spaceship.setTexture(spaceshipTexture);
    textureLoaded = true;
}

void Spaceship::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        spaceship.move(speed, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        spaceship.move(-speed, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spaceship.move(0.f, speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        spaceship.move(0.f, -speed);
    }
}

void Spaceship::update()
{
    move();
}

void Spaceship::draw(sf::RenderWindow& window)
{
    window.draw(spaceship);
}
