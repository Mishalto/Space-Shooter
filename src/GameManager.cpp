#include "../include/GameManager.hpp"

GameManager::GameManager()
{
}

void GameManager::update()
{
    checkInput();
    if(!bullets.empty())
    {
        for(std::size_t index = 0; index < bullets.size(); ++index)
        {
            bullets[index].moveBullet();
            if(bullets[index].isOffScreen())
            {
                bullets.erase(bullets.begin() + index);
            }
        }
    }
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
        bullets.emplace_back(Bullet{});
        bullets.back().setPos(ship.getPosX(), ship.getPosY());
    }
}

void GameManager::draw(sf::RenderWindow& window)
{
    ship.draw(window);
    if(!bullets.empty())
    {
        for(const auto& bullet : bullets)
        {
            bullet.draw(window);
        }
    }
}
