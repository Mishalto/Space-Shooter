#pragma once

#include "../include/Spaceship.hpp"
#include "../include/Bullet.hpp"

class GameManager
{
private:
    Spaceship ship;
    Bullet bullet;

    void checkInput();
public:
    GameManager();

    void update();
    void draw(sf::RenderWindow& window);
};
