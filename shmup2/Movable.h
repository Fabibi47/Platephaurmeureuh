#pragma once
#include "AComponent.h"
#include "box2d/box2d.h"

class Movable : public AComponent
{
	float moveSpeed;
	b2Vec2 direction;
public:
	Movable(Entity* parent, float moveSpeed = 0, b2Vec2 direction = { 0 , 0 });
	virtual void Update(float dt) override;
	void setMoveSpeed(float newMoveSpeed);
	void setDirection(b2Vec2 newDir);
	float getMoveSpeed();
	b2Vec2 getDirection();
};

