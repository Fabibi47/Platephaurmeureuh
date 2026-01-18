#pragma once
#include "PlayerBehavior.h"
#include "Entity.h"
#include "Movable.h"
#include "Scene.h"
#include "RigidBody.h"
#include <SFML/Graphics.hpp>
#include "Transformable.h"
#include "Collider.h"
#include "SwitcherBehavior.h"

PlayerBehavior::PlayerBehavior(Entity* parent) : AComponent(parent){}

void PlayerBehavior::Update(float dt) {
	Movable* movableC = parent->GetComponent<Movable>();
	RigidBody* rb = parent->GetComponent<RigidBody>();
	movableC->setDirection({ 0 , 0 });
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		movableC->setDirection({ movableC->getDirection().x + 1, movableC->getDirection().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		movableC->setDirection({ movableC->getDirection().x - 1, movableC->getDirection().y });
	}
}

void PlayerBehavior::BeginCollision(Collider* me, Collider* other) {
	isGrounded = true;
}

void PlayerBehavior::SetGrounded(bool grounded) {
	isGrounded = grounded;
}

bool PlayerBehavior::GetIsGrounded() {
	return isGrounded;
}

void PlayerBehavior::EndCollision(Collider* me, Collider* other) {
	if (isGrounded && !me->isColliding()) isGrounded = false;
}