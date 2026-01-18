#pragma once
#include "BoxCollider.h"
#include "Entity.h"
#include "Scene.h"
#include "Engine.h"
#include "Physics.h"
#include "RigidBody.h"

BoxCollider::BoxCollider(Entity* parent, b2Vec2 size) : Collider(parent), size(size) {
	float scale = Physics::WorldScale;
	RigidBody* rb = parent->GetComponent<RigidBody>();
	b2Polygon box = b2MakeBox((size.x / 2.0f) / scale, (size.y / 2.0f) / scale);
	shape.density = 1;
	shapeId = b2CreatePolygonShape(rb->getBody(), &shape, &box);
	b2Shape_SetFriction(shapeId, 1.f);
}

void BoxCollider::Update(float dt) {}

void BoxCollider::setSize(b2Vec2 newSize) {
	float scale = Physics::WorldScale;
	b2Polygon box = b2MakeBox(newSize.x / scale, newSize.y / scale);
	size = newSize;
	b2Shape_SetPolygon(shapeId, &box);
}