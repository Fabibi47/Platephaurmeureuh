#pragma once
#include "CapsuleCollider.h"
#include "Entity.h"
#include "Physics.h"
#include "RigidBody.h"

CapsuleCollider::CapsuleCollider(Entity* parent, b2Vec2 size) : size(size), Collider(parent) {
	float scale = Physics::WorldScale;
	RigidBody* rb = parent->GetComponent<RigidBody>();
	float radius = (size.x / scale) / 2;
	float height = (size.y / scale);
	b2Capsule capsule;
	capsule.radius = radius;
	float circlePos = (height / 2.f) - radius;
	if (circlePos < 0) circlePos = 0;
	capsule.center1 = { 0.f , -circlePos };
	capsule.center2 = { 0.f , circlePos };
	shape.density = 0.01f;
	shapeId = b2CreateCapsuleShape(rb->getBody(), &shape, &capsule);
	b2Shape_SetFriction(shapeId, 2.f);
	b2Shape_SetRestitution(shapeId, 0);
	b2Body_SetFixedRotation(rb->getBody(), true);
	/*b2Capsule* capsule = new b2Capsule;
	capsule->radius = (size.x/scale) / 2;
	capsule->center2 = { b2Body_GetTransform(rb.getBody()).p.x + (size.x / scale), b2Body_GetTransform(rb.getBody()).p.y + (size.y / scale) / 2 - capsule->radius };
	capsule->center1 = { b2Body_GetTransform(rb.getBody()).p.x + (size.x / scale), b2Body_GetTransform(rb.getBody()).p.y - (size.y/scale)/2 + capsule->radius };
	shapeId = b2CreateCapsuleShape(rb.getBody(), &shape, capsule);*/
}

void CapsuleCollider::Update(float dt) {}


void CapsuleCollider::setSize(b2Vec2 newSize) {
	size = newSize;
}