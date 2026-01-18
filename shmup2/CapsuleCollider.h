#pragma once
#include <box2d/box2d.h>
#include "AComponent.h"
#include "Collider.h"

class CapsuleCollider : public Collider
{
	b2Vec2 size;
public:
	CapsuleCollider(Entity* parent, b2Vec2 size = { 1, 1 });
	void Update(float dt) override;
	void setSize(b2Vec2 newSize);
};

