#pragma once
#include "AComponent.h"
#include "SFML/Graphics.hpp"

class Crouch : public AComponent
{
	bool isCrouching = false;
	float originalMs;
	float crouchMs;
	sf::Sprite originalSprite;
	sf::Sprite* crouchSprite;
public:
	Crouch(Entity* parent, sf::Sprite* crouchSprite, float crouchMs = 5);
	void Update(float dt) override;
	void StartCrouching();
	void StopCrouching();
	bool GetIsCrouching();
};

