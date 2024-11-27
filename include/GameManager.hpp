#pragma once

#include <memory>
#include <vector>

#include "../include/Spaceship.hpp"
#include "../include/Bullet.hpp"
#include "../include/Enemy.hpp"

class GameManager
{
private:
    Spaceship ship;
    Enemy UFO;
    std::vector<Bullet> bullets;

    void checkInput();
public:
    GameManager();

    void update();
    void draw(sf::RenderWindow& window);

    void fire();
    void moveBullets();
    void moveUFO();

    sf::Clock Timer;
    float fireRateLimit = 0.3f;
};
