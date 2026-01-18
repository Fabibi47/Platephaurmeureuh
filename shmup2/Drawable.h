#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"
#include "Camera.h"

class Drawable : public AComponent
{
	sf::Sprite sprite;
public:
	Drawable(Entity* parent, sf::Texture& texture, sf::Vector2i spritePos, bool repeat = false);
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) const;
	sf::Sprite& getSprite();
	void setSprite(sf::Sprite* newSprite, sf::Vector2i spritePos, sf::Vector2i spriteSize);
};