#pragma once

#include <SFML/Graphics.hpp>

class Spaceship
{
private:
    sf::Texture spaceshipTexture;
    sf::Sprite spaceship;

    const float speed = 5.f;

    bool textureLoaded = false;
public:
    Spaceship();
    
    void loadTexture();
    void move();
    void update();
    void draw(sf::RenderWindow& window);
};
