#include "Collider.h"
#include <iostream>

Collider::Collider(Entity* parent) : AComponent(parent), shape(b2DefaultShapeDef()) {
	shape.enableContactEvents = true;
	shapeId = b2_nullShapeId;
}

bool Collider::isColliding() {
	return collisionCount > 0;
}

void Collider::Update(float dt) {
	
}

void Collider::setDensity(float newDensity) {
	b2Shape_SetDensity(shapeId, newDensity, true);
}

void Collider::setFriction(float newFriction) {
	b2Shape_SetFriction(shapeId, newFriction);
}

void Collider::increaseCollisionCount() {
	collisionCount++;
}

void Collider::decreaseCollisionCount() {
	collisionCount--;
}

b2ShapeId Collider::getShape() {
	return shapeId;
}