#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/Spaceship.hpp"
#include "../include/constants.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::weight, Constants::height), "Space Shooter", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    Spaceship ship{};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    ship.update();

        window.clear();
        ship.draw(window);
        window.display();
    }

    return 0;
}
