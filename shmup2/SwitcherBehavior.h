#pragma once
#include "AComponent.h"
#include "ICollisionEvent.h"

class SwitcherBehavior : public AComponent, public ICollisionEvent
{
public:
	SwitcherBehavior(Entity* parent);
	void Update(float dt) override {}
	void BeginCollision(Collider* me, Collider* other);
	void EndCollision(Collider* me, Collider* other) {}
};

