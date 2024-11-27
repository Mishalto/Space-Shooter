#pragma once

#include <SFML/Graphics.hpp>

class Spaceship
{
private:
    sf::Texture spaceshipTexture;
    sf::Sprite spaceship;

    float shipSpeed = 8.f;

    bool textureLoaded = false;
public:
    Spaceship();
    
    void loadTextures();
    void moveShip(float x, float y);
    void draw(sf::RenderWindow& window);

    float getSpeed() const;
    float getPosX() const;
    float getPosY() const;
};
