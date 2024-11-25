#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/constants.h"
#include "../include/Spaceship.hpp"
#include "../include/Bullet.hpp"
#include "../include/GameManager.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::Resolution::weight, Constants::Resolution::height), "Space Shooter", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    GameManager manager{};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        manager.update();

        window.clear();
        manager.draw(window);
        window.display();
    }

    return 0;
}
