#include "Entity.h"
#include "Drawable.h"

Entity::Entity(Scene* scene) : scene(scene) {}

void Entity::AddComponents() {
	for (AComponent* newComponent : componentsToAdd) {
		components.push_back(newComponent);
	}
}

void Entity::RemoveComponents() {
	for (AComponent* component : componentsToRemove) {

	}
}

void Entity::AddComponentToAdd(AComponent* newComponent) {
	componentsToAdd.push_back(newComponent);
}

void Entity::AddComponentToRemove(AComponent* component) {
	componentsToRemove.push_back(component);
}

void Entity::Update(float dt) {
	if (!pendingDestroy) {
		for (AComponent* component : components) {
			component->Update(dt);
		}
	}
}

void Entity::Draw(sf::RenderWindow& window)
{
	if (Drawable* drawableComponent = GetComponent<Drawable>())
		drawableComponent->Draw(window);
}

Scene* Entity::getScene() {
	return scene;
}

void Entity::setPendingDestroy(bool pending) {
	pendingDestroy = pending;
}

bool Entity::isPendingDestroy() {
	return pendingDestroy;
}

void Entity::AddComponent(AComponent* newComponent){
	components.push_back(newComponent);
}
