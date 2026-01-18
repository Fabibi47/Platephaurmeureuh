#pragma once
#include <SFML/Graphics.hpp>
#include "RigidBody.h"
#include "Physics.h"
#include "Collider.h"
#include "Entity.h"
#include "Transformable.h"
#include "Scene.h"
#include "Engine.h"

RigidBody::RigidBody(Entity* parent, bool isDynamic) : AComponent(parent), dynamic(isDynamic) {
	b2BodyDef bodyDef = b2DefaultBodyDef();
	if (isDynamic)
		bodyDef.type = b2_dynamicBody;
	sf::Vector2f parentPos = parent->GetComponent<Transformable>()->getPosition();
	float scale = Physics::WorldScale;
	bodyDef.position = { parentPos.x / scale , parentPos.y  / scale};
	body = b2CreateBody(parent->getScene()->getEngine()->getPhysics()->getWorldId(), &bodyDef);
}

b2BodyId RigidBody::getBody() {
	return body;
}

void RigidBody::UpdateBodyPosition(){
	Transformable* transform = parent->GetComponent<Transformable>();
	float scale = Physics::WorldScale;
	b2Vec2 pos = { transform->getPosition().x / scale, transform->getPosition().y / scale };

	b2Rot rot = b2MakeRot(parent->GetComponent<Transformable>()->getRotation().asRadians());
	b2Body_SetTransform(body, pos, rot);
}

void RigidBody::UpdateGraphicPosition() {
	Transformable* transform = parent->GetComponent<Transformable>();
	b2Vec2 pos = b2Body_GetPosition(body);
	b2Rot rot = b2Body_GetRotation(body);
	sf::Angle angle = sf::radians(b2Rot_GetAngle(rot));
	float scale = Physics::WorldScale;
	transform->setPosition({ pos.x*scale, pos.y*scale });
	transform->setRotation(angle);
}

void RigidBody::Update(float dt) {}