#include "AComponent.h"

AComponent::AComponent(Entity* parent) : parent(parent){}
Entity* AComponent::getParent() {
	return parent;
}