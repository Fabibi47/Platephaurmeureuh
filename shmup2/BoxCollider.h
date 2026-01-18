#pragma once
#include <box2d/box2d.h>
#include "Collider.h"

class BoxCollider : public Collider
{
	b2Vec2 size;
public:
	BoxCollider(Entity* parent, b2Vec2 size = {1, 1});
	void Update(float dt) override;
	void setSize(b2Vec2 newSize);
};

