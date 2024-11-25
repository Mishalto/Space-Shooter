#pragma once

#include <SFML/Graphics.hpp>

class Spaceship
{
private:
    sf::Texture spaceshipTexture;
    sf::Sprite spaceship;

    sf::Texture bulletTexture;
    sf::Sprite bullet;

    const float shipSpeed = 5.f;
    [[maybe_unused]]const float bulletSpeed = 5.f;

    bool textureLoaded = false;
public:
    Spaceship();
    
    void loadTexture();
    void move();
    void update();
    void draw(sf::RenderWindow& window);
};
