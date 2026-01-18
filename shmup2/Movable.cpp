#pragma once
#include "Movable.h"
#include "Transformable.h"
#include "Entity.h"
#include "RigidBody.h"

Movable::Movable(Entity* parent, float moveSpeed, b2Vec2 direction) : AComponent(parent), moveSpeed(moveSpeed), direction(direction) {}

void Movable::Update(float dt) {
	if (direction != b2Vec2{ 0, 0 }) {
		RigidBody* rb = parent->GetComponent<RigidBody>();
		b2Body_ApplyForceToCenter(rb->getBody(), direction * moveSpeed * dt * 60, true);
		b2Vec2 velocity = b2Body_GetLinearVelocity(rb->getBody());
		if (velocity.x > 5.0f) {
			velocity.x = 5.0f;
			b2Body_SetLinearVelocity(rb->getBody(), velocity);
		}
		if (velocity.x < -5.0f) {
			velocity.x = -5.0f;
			b2Body_SetLinearVelocity(rb->getBody(), velocity);
		}
	}
}

void Movable::setMoveSpeed(float newMoveSpeed) {
	moveSpeed = newMoveSpeed;
}

void Movable::setDirection(b2Vec2 newDir) {
	direction = newDir;
}

float Movable::getMoveSpeed() {
	return moveSpeed;
}

b2Vec2 Movable::getDirection() {
	return direction;
}