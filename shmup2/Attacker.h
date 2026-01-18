#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

class Attacker: public AComponent
{
	int damage;
	float attackSpeed;
	sf::Clock attackTimer;
	sf::Vector2f direction;
public:
	Attacker(Entity* parent, float attackSpeed = 0, sf::Vector2f direction = { 0.f, 1.f}, int damage = 0);
	virtual void Update(float dt) override;
	void setAttackSpeed(float newAttackSpeed);
	void Attack();
	float getAttackSpeed();
	void setDamage(int newDamage);
	int getDamage();
};

