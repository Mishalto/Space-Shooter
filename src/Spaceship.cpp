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
    bullet.setPosition(sf::Vector2f(100, 100));
}

void Spaceship::loadTexture()
{
    if (!spaceshipTexture.loadFromFile("assets/spaceship.png"))
    {
        std::cerr << "I can't load a spaceship\n";
    }
    spaceship.setTexture(spaceshipTexture);

    if(!bulletTexture.loadFromFile("assets/bullet.png"))
    {
        std::cerr << "I can't load a bullet\n";
    }
    bullet.setTexture(bulletTexture);
    textureLoaded = true;
}

void Spaceship::move()
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
    move();
}

void Spaceship::draw(sf::RenderWindow& window)
{
    window.draw(spaceship);
    window.draw(bullet);
}
