#pragma once

class Collider;
class ICollisionEvent
{
public:
	virtual void BeginCollision(Collider* me, Collider* other) = 0;
	virtual void EndCollision(Collider* me, Collider* other) = 0;
};

