#include "../include/GameManager.hpp"
#include "../include/constants.h"

GameManager::GameManager()
{
}

void GameManager::update()
{
    checkInput();
    moveBullets();
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
        }
    }
}

void GameManager::draw(sf::RenderWindow& window)
{
    ship.draw(window);
    UFO.draw(window);
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

