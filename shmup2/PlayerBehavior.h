#pragma once
#include "AComponent.h"
#include "ICollisionEvent.h"

class PlayerBehavior : public AComponent, public ICollisionEvent
{
	bool isGrounded = true;
public:
	PlayerBehavior(Entity* parent);
	virtual void Update(float dt) override;
	void BeginCollision(Collider* me, Collider* other);
	void EndCollision(Collider* me, Collider* other);
	void SetGrounded(bool grounded);
	bool GetIsGrounded();
};