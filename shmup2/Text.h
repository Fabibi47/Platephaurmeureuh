#pragma once
#include "AComponent.h"
#include "SFML/Graphics.hpp"

class Entity;
class Text : public AComponent
{
	sf::Text text;
	std::string fontPath;
public:
	Text(Entity* parent, std::string text, sf::Font font, int size = 12, sf::Color color = sf::Color::White);
	virtual void Update(float dt) override {}
	virtual void Draw(sf::RenderWindow& window) const;
	sf::Text getText();
	void setText(sf::Text);
	std::string getString();
	void setString(std::string newString);
	std::string getFont();
	void setFont(sf::Font& newFont, std::string fontPath);
	int getSize();
	void setSize(int newSize);
	sf::Color getColor();
	void setColor(sf::Color newColor);
};

