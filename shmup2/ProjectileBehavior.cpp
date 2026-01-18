#include "ProjectileBehavior.h"
#include "Entity.h"
#include "Transformable.h"
#include "Drawable.h"
#include "Scene.h"
#include "Damageable.h"
#include <iostream>

ProjectileBehavior::ProjectileBehavior(Entity* parent, int damage) : AComponent(parent), damage(damage) {}

void ProjectileBehavior::Update(float dt) {
	Transformable* transform = parent->GetComponent<Transformable>();
	if (transform->getPosition().y >= 600 || transform->getPosition().y <= 0) {
		parent->setPendingDestroy(true);
	}
	Drawable* draw = parent->GetComponent<Drawable>();
	Scene* scene = parent->getScene();
	for (Entity* entity : scene->getEntities()) {
		if (Drawable* entityDraw = entity->GetComponent<Drawable>()) {
			if (Damageable* entityDamage = entity->GetComponent<Damageable>()) {
				if (draw->getSprite().getGlobalBounds().findIntersection(entityDraw->getSprite().getGlobalBounds())) {
					entityDamage->takeDamage(damage);
					parent->setPendingDestroy(true);
				}
			}
		}
	}
}

int ProjectileBehavior::getDamage() {
	return damage;
}

void ProjectileBehavior::setDamage(int newDamage) {
	damage = newDamage;
}