#pragma once
#include "AComponent.h"
#include "SFML/Graphics.hpp"

class Camera : public AComponent
{
	sf::View* view;
public:
	Camera(Entity* parent, sf::Vector2f size);
	void Update(float dt) override;
	const sf::View* getView() { return view; }
	~Camera();
};

