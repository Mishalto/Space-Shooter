#include <iostream>

#include "../include/TextureManager.hpp"

TextureManager::TextureManager()
{
    for(std::size_t index = 0; index < filePaths.size(); ++index)
    {
        auto texture = std::make_unique<sf::Texture>();
        if(!texture->loadFromFile(filePaths[index]))
        {
            std::cout << "Failed to load: " << filePaths[index] << '\n';
        }
        textureStorage[index + 1] = std::move(texture);
    }

}

const std::shared_ptr<sf::Texture> TextureManager::getTexture(int key)
{
    auto it = textureStorage.find(key);
    if(it != textureStorage.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}
