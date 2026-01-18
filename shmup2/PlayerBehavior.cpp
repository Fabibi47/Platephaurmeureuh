#pragma once
#include "PlayerBehavior.h"
#include "Entity.h"
#include "Movable.h"
#include "Scene.h"
#include "RigidBody.h"
#include <SFML/Graphics.hpp>
#include "Transformable.h"
#include "Collider.h"
#include <iostream>
#include "SwitcherBehavior.h"

PlayerBehavior::PlayerBehavior(Entity* parent) : AComponent(parent){}

void PlayerBehavior::Update(float dt) {
	Movable* movableC = parent->GetComponent<Movable>();
	RigidBody* rb = parent->GetComponent<RigidBody>();
	std::cout << "Masse : " << b2Body_GetMass(rb->getBody()) << std::endl;
	movableC->setDirection({ 0 , 0 });
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		movableC->setDirection({ movableC->getDirection().x + 1, movableC->getDirection().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		movableC->setDirection({ movableC->getDirection().x - 1, movableC->getDirection().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isGrounded) {
		b2Body_ApplyLinearImpulseToCenter(rb->getBody(), { 0, -5 }, true);
		isGrounded = false;
	}
}


void PlayerBehavior::BeginCollision(Collider* me, Collider* other) {
	isGrounded = true;
}