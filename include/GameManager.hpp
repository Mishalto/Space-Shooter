#pragma once

#include <memory>
#include <vector>

#include "../include/Spaceship.hpp"
#include "../include/Bullet.hpp"

class GameManager
{
private:
    Spaceship ship;
    std::vector<Bullet> bullets;

    void checkInput();
public:
    GameManager();

    void update();
    void draw(sf::RenderWindow& window);

    sf::Clock fireRate;
    float fireRateLimit = 0.5f;
};
