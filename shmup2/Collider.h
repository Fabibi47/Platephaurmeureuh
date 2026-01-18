#pragma once
#include "AComponent.h"
#include <box2d/box2d.h>

class Collider : public AComponent
{
protected:
	int collisionCount = 0;
	b2ShapeDef shape;
	b2ShapeId shapeId;
public:
	Collider(Entity* parent);
	void Update(float dt) override;
	bool isColliding();
	void setDensity(float newDensity);
	void setFriction(float newFriction);
	void increaseCollisionCount();
	void decreaseCollisionCount();
	b2ShapeId getShape();
	friend class Physics;
};

