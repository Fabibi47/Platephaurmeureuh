#pragma once
#include "AComponent.h"

class Damageable : public AComponent
{
	int hpMax;
	int hp;
public:
	Damageable(Entity* parent, int hpMax);
	virtual void Update(float dt) override;
	int getHp();
	int getHpMax();
	void setHpMax(int hpMax);
	void takeDamage(int damage);
};

