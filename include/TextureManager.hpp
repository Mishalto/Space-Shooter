#pragma once

#include <unordered_map>
#include <memory>

#include <SFML/Graphics.hpp>

class TextureManager
{
private:
    std::unordered_map<int, std::shared_ptr<sf::Texture>> textureStorage;
    std::vector<std::string> filePaths{"../assets/spaceship.png", "../assets/bullet.png", "../assets/enemy.png", "../assets/background.png"};
public:
    TextureManager();

    const std::shared_ptr<sf::Texture> getTexture(int key);
};
