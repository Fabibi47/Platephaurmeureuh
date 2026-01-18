#include "Damageable.h"
#include "Entity.h"
#include <iostream>

Damageable::Damageable(Entity* parent, int maxHp) : AComponent(parent) , hpMax(maxHp), hp(maxHp){}

int Damageable::getHp() {
	return hp;
}

int Damageable::getHpMax() {
	return hpMax;
}

void Damageable::setHpMax(int newHpMax) {
	hpMax = newHpMax;
}

void Damageable::takeDamage(int damage) {
	hp -= damage;
	if (hp < 0)
		hp = 0;
	if (hp > hpMax)
		hp = hpMax;
}

void Damageable::Update(float dt) {
	if (hp <= 0)
		parent->setPendingDestroy(true);
}