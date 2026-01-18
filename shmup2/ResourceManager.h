#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class ResourceManager
{
private:
	static ResourceManager* m_instance;
	std::map<std::string, sf::Texture*> _textureCache;
	std::map<std::string, sf::Font*> _fontCache;
protected:
	ResourceManager() {};
public:
	static ResourceManager* getInstance();
	sf::Texture* LoadTexture(std::string texturePath);
	sf::Font* LoadFont(std::string fontPath);
};