#pragma once
#include "AComponent.h"

class ProjectileBehavior : public AComponent
{
	int damage;
public:
	ProjectileBehavior(Entity* parent, int damage = 0);
	virtual void Update(float dt) override;
	int getDamage();
	void setDamage(int newDamage);
};

