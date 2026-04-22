#include "Transformable.h"

Transformable::Transformable(Entity* parent, sf::Vector2f pos, sf::Vector2f size, sf::Angle rotation) : AComponent(parent), size(size), firstPos(pos) {
	setOrigin({ size.x / 2, size.y / 2 });
	setPosition(pos);
	setRotation(rotation);
}

sf::Vector2i Transformable::getSize() {
	return size;
}

void Transformable::setSize(sf::Vector2i newSize) {
	size = newSize;
}