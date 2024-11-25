#include <iostream>

#include "../include/Spaceship.hpp"

Spaceship::Spaceship()
{
    spaceship.setPosition(sf::Vector2f(1920/2, 1080 - spaceship.getLocalBounds().height));
    std::cout << spaceship.getGlobalBounds().height;
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
    if(!textureLoaded)
    {
        loadTexture();
    }
    window.draw(spaceship);
}
