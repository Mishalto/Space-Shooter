#include "../include/GameManager.hpp"

GameManager::GameManager()
{
}

void GameManager::update()
{
    checkInput();
    bullet.moveBullet();
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
        bullet.setPos(ship.getPosX(), ship.getPosY());
    }
}

void GameManager::draw(sf::RenderWindow& window)
{
    ship.draw(window);
    bullet.draw(window);
}
