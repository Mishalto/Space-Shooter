#pragma once

#include <memory>
#include <vector>

#include <SFML/Audio.hpp>

#include "../include/Spaceship.hpp"
#include "../include/Bullet.hpp"
#include "../include/Enemy.hpp"

class GameManager
{
private:
    Spaceship ship;
    std::vector<Bullet> bullets;
    Enemy UFO;

    sf::Music fireSound;

    void checkInput();
public:
    GameManager();

    void update();
    void draw(sf::RenderWindow& window);

    void fire();
    void moveBullets();
    void moveUFO();
    void checkCollision();

    sf::Clock Timer;
    float fireRateLimit = 0.3f;
};
