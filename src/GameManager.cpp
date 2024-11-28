#include "../include/GameManager.hpp"
#include "../include/constants.h"

#include <iostream>

GameManager::GameManager()
{
    fireSound.openFromFile("../assets/fire.wav");
    fireSound.setVolume(40.f);
}

void GameManager::update()
{
    checkInput();
    moveBullets();
    checkCollision();
    UFO.move();
}

void GameManager::checkInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        ship.moveShip(0.f, -ship.getSpeed());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        ship.moveShip(-ship.getSpeed(), 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        ship.moveShip(0.f, ship.getSpeed());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ship.moveShip(ship.getSpeed(), 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(Timer.getElapsedTime().asSeconds() > fireRateLimit)
        {
            fire();
            fireSound.play();
        }
    }
}

void GameManager::draw(sf::RenderWindow& window)
{
    ship.draw(window);
    if(UFO.isAlive())
    {
        UFO.draw(window);
    }
    if(!bullets.empty())
    {
        for(const auto& bullet : bullets)
        {
            bullet.draw(window);
        }
    }
}

void GameManager::fire()
{
    if (Timer.getElapsedTime().asSeconds() > fireRateLimit)
    {
        bullets.emplace_back(Bullet{});
        bullets.back().setPos(ship.getPosX() + Constants::Offset::x, ship.getPosY() - (-Constants::Offset::y));
        Timer.restart();
    }
}

void GameManager::moveBullets()
{
    if (!bullets.empty())
    {
        for (std::size_t index = 0; index < bullets.size(); ++index)
        {
            bullets[index].moveBullet();
            if (bullets[index].isOffScreen())
            {
                bullets.erase(bullets.begin() + index);
            }
        }
    }
}

void GameManager::checkCollision()
{
    for(std::size_t i = 0; i < bullets.size(); ++i)
    {
        if(bullets[i].getSprite().getGlobalBounds().intersects(UFO.getTexture().getGlobalBounds()))
        {
            bullets.erase(bullets.begin() + i);
            UFO.reduceHealth();
        }
    }
}
