#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

class TextureManager
{
private:
    std::map<int, std::shared_ptr<sf::Texture>> textureStorage;
    std::vector<std::string> filePaths{"../assets/spaceship.png", "../assets/bullet.png"};
public:
    TextureManager();

    const std::shared_ptr<sf::Texture> getTexture(int key);
};
