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
	if (circlePos < 0) circlePos = 0.01f;
	capsule.center1 = { 0.f , -circlePos + 1 };
	capsule.center2 = { 0.f , circlePos + 1 };
	shape.density = 0.0175f;
	shapeId = b2CreateCapsuleShape(rb->getBody(), &shape, &capsule);
	b2Shape_SetFriction(shapeId, 2.f);
	b2Shape_SetRestitution(shapeId, 0);
	b2Body_SetFixedRotation(rb->getBody(), true);
}

void CapsuleCollider::Update(float dt) {}


void CapsuleCollider::setSize(b2Vec2 newSize) {
	float scale = Physics::WorldScale;
	RigidBody* rb = parent->GetComponent<RigidBody>();
	size = newSize;
	b2Capsule capsule;
	capsule.radius = (newSize.x / scale) / 2.f;
	float height = (newSize.y / scale);
	float minimumHeight = (capsule.radius * 2.0f) + 0.05f;
	if (height < minimumHeight) height = minimumHeight;
	float circlePos = (height / 2.f) - capsule.radius;
	capsule.center1 = { 0.f , -circlePos + 1 };
	capsule.center2 = { 0.f , circlePos + 1 };
	if (b2Shape_IsValid(shapeId)) {
		b2Shape_SetCapsule(shapeId, &capsule);
		b2BodyId bodyId = rb->getBody();
		b2Body_ApplyMassFromShapes(bodyId);
		b2Body_SetAwake(bodyId, true);
	}
}