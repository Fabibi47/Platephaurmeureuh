#pragma once
#include "AComponent.h"

class Jump : public AComponent
{
	float jumpForce;
public:
	Jump(Entity* parent, float jumpForce);
	void Update(float dt) override;
	float GetJumpForce();
	void SetJumpForce(float newJumpForce);
};

