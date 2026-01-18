#pragma once

class Entity;
class AComponent
{
protected:
	Entity* parent;
public:
	AComponent(Entity* parent);
	virtual void Update(float dt) = 0;
	Entity* getParent();
};

