#pragma once
#include "Crouch.h"
#include "Entity.h"
#include "Movable.h"
#include "Drawable.h"
#include "CapsuleCollider.h"
#include "RigidBody.h"

Crouch::Crouch(Entity* parent, sf::Sprite* crouchSprite, float crouchMs) : AComponent(parent), crouchSprite(crouchSprite), crouchMs(crouchMs), originalSprite(parent->GetComponent<Drawable>()->getSprite()) {
	originalMs = parent->GetComponent<Movable>()->getMoveSpeed();
}

void Crouch::Update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
		if (!isCrouching) {
			StartCrouching();
		}
	}
	else {
		if (isCrouching) {
			StopCrouching();
		}
	}
}

void Crouch::StartCrouching() {
	parent->GetComponent<Drawable>()->setSprite(crouchSprite, { 0, 0 }, { 256, 256 });
	parent->GetComponent<CapsuleCollider>()->setSize({ 165, 100 });
	parent->GetComponent<Movable>()->setMoveSpeed(crouchMs);
	isCrouching = true;
}

void Crouch::StopCrouching() {
	parent->GetComponent<Drawable>()->setSprite(&originalSprite, { 0, 0 }, { 256, 256 });
	parent->GetComponent<CapsuleCollider>()->setSize({ 165, 200 });
	parent->GetComponent<Movable>()->setMoveSpeed(originalMs);
	isCrouching = false;
}

bool Crouch::GetIsCrouching() {
	return isCrouching;
}