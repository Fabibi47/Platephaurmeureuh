#pragma once
#include <box2d/box2d.h>
#include <vector>
#include "Entity.h"

class Physics
{
protected:
	static b2WorldId world;
public:
	b2Vec2 gravity;
	Physics(b2Vec2 gravity);
	~Physics();
	void Update(std::vector<Entity*> entities);
	static const float WorldScale;
	b2WorldId getWorldId();
	void Clear();
};