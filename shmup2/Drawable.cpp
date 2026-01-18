#pragma once
#include "Drawable.h"
#include "Transformable.h"
#include "Entity.h"

Drawable::Drawable(Entity* parent, sf::Texture& texture, sf::Vector2i spritePos, bool repeat) : AComponent(parent), sprite(texture) {
	texture.setRepeated(repeat);
	sf::Vector2i size = parent->GetComponent<Transformable>()->getSize();
	sprite.setTextureRect({ spritePos, size });
}

void Drawable::Update(float dt) {}

void Drawable::Draw(sf::RenderWindow& window) const {
	sf::RenderStates r = sf::RenderStates::Default;
	r.transform *= parent->GetComponent<Transformable>()->getTransform();
	window.draw(sprite, r);
}

sf::Sprite& Drawable::getSprite() {
	return sprite;
}

void Drawable::setSprite(sf::Sprite* newSprite, sf::Vector2i spritePos, sf::Vector2i spriteSize) {
	sprite = *newSprite;
	sprite.setTextureRect({ spritePos, spriteSize });
}