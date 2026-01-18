#pragma once
#include <box2d/box2d.h>
#include "AComponent.h"

class RigidBody : public AComponent
{
	bool dynamic;
	b2BodyId body;
public:
	RigidBody(Entity* parent, bool isDynamic);
	virtual void Update(float dt) override;
	b2BodyId getBody();
	void UpdateBodyPosition();
	void UpdateGraphicPosition();
};

