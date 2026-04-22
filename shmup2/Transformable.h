#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

class Transformable : public AComponent, public sf::Transformable
{
	sf::Vector2i size;
public:
	sf::Vector2f firstPos;
	Transformable(Entity* parent, sf::Vector2f pos = { 0 , 0 }, sf::Vector2f size = { 32, 32 }, sf::Angle rotation = sf::degrees(0));
	virtual void Update(float dt) override {};
	sf::Vector2i getSize();
	void setSize(sf::Vector2i newSize);
};

