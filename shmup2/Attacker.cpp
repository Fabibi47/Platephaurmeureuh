#pragma once
#include "Attacker.h"
#include "Entity.h"
#include "Transformable.h"
#include "Movable.h"
#include "Drawable.h"
#include "ProjectileBehavior.h"
#include "Scene.h"
#include "ResourceManager.h"

Attacker::Attacker(Entity* parent, float attackSpeed, sf::Vector2f direction, int damage) : AComponent(parent), attackSpeed(attackSpeed), direction(direction), damage(damage) {
	attackTimer.restart();
}

void Attacker::Update(float dt) {
	float elapsed = attackTimer.getElapsedTime().asSeconds();
	if (elapsed >= attackSpeed) {
		Attack();
		attackTimer.restart();
	}
}

void Attacker::Attack() {
	Entity* projectile = new Entity(parent->getScene());
	projectile->AddComponent(new Transformable(projectile, parent->GetComponent<Transformable>()->getPosition(), {16, 16}, parent->GetComponent<Transformable>()->getRotation()));
	projectile->AddComponent(new Movable(projectile, 300, direction));
	projectile->AddComponent(new Drawable(projectile, *ResourceManager::getInstance()->Load("tiles_packed.png"), {0, 0}));
	projectile->AddComponent(new ProjectileBehavior(projectile, damage));
	projectile->AddComponents();
	sf::Vector2f pos = parent->GetComponent<Transformable>()->getPosition();
	projectile->GetComponent<Transformable>()->setPosition({ pos.x + 8, pos.y + 16 * direction.y });
	parent->getScene()->AddEntityToAdd(projectile);
}

void Attacker::setAttackSpeed(float newAttackSpeed) {
	attackSpeed = newAttackSpeed;
}

float Attacker::getAttackSpeed() {
	return attackSpeed;
}

int Attacker::getDamage() {
	return damage;
}

void Attacker::setDamage(int newDamage) {
	damage = newDamage;
}