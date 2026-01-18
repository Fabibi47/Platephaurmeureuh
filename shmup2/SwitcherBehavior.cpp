#pragma once
#include "SwitcherBehavior.h"
#include "Collider.h"
#include "Entity.h"
#include "PlayerBehavior.h"
#include "Scene.h"

SwitcherBehavior::SwitcherBehavior(Entity* parent) : AComponent(parent) {}

void SwitcherBehavior::BeginCollision(Collider* me, Collider* other) {
	if (other->getParent()->GetComponent<PlayerBehavior>()) {
		parent->getScene()->setSwitch(true, 2);
	}
}