#pragma once
#include "Jump.h"
#include "Entity.h"
#include "PlayerBehavior.h"
#include "RigidBody.h"

Jump::Jump(Entity* parent, float jumpForce) : AComponent(parent), jumpForce(jumpForce){}

void Jump::Update(float dt) {
	RigidBody* rb = parent->GetComponent<RigidBody>();
	PlayerBehavior* player = parent->GetComponent<PlayerBehavior>();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player->GetIsGrounded()) {
		b2Body_ApplyLinearImpulseToCenter(rb->getBody(), { 0, -jumpForce }, true);
		player->SetGrounded(false);
	}
}

void Jump::SetJumpForce(float newJumpForce) {
	jumpForce = newJumpForce;
}

float Jump::GetJumpForce() {
	return jumpForce;
}