#pragma once
#include "AComponent.h"
#include "ICollisionEvent.h"

class SwitcherBehavior : public AComponent, public ICollisionEvent
{
	int sceneIndex;
public:
	SwitcherBehavior(Entity* parent, int sceneIndex);
	void Update(float dt) override {}
	void BeginCollision(Collider* me, Collider* other);
	void EndCollision(Collider* me, Collider* other) {}
};

