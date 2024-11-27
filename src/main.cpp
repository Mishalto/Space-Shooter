#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/constants.h"
#include "../include/GameManager.hpp"
#include "../include/Enemy.hpp"
#include "../include/LoadedTextures.hpp"

void closeCheck(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::Resolution::weight, Constants::Resolution::height), "Space Shooter", sf::Style::None);
    window.setFramerateLimit(60);

    GameManager manager;
    sf::Sprite background;
    background.setTexture(*(textures.getTexture(4)));
    while (window.isOpen())
    {
        closeCheck(window);

        manager.update();

        window.clear();
        window.draw(background);
        manager.draw(window);
        window.display();
    }

    return 0;
}
