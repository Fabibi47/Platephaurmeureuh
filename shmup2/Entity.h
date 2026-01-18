#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "AComponent.h"

class Scene;
class Entity
{
	bool pendingDestroy = false;
	Scene* scene;
	std::vector<AComponent*> components;
	std::vector<AComponent*> componentsToAdd;
	std::vector<AComponent*> componentsToRemove;
public:
	Entity(Scene* scene);
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void AddComponents();
	void RemoveComponents();
	void AddComponentToAdd(AComponent* newComponent);
	void AddComponentToRemove(AComponent* component);
	Scene* getScene();
	void setPendingDestroy(bool);
	bool isPendingDestroy();
	void AddComponent(AComponent* newComponent);

	template<typename T>
	void RemoveComponent(T) {
		for (int i = 0; i < components.size(); i++) {
			if (T* component = dynamic_cast<T*>(components[i])) {
				components.erase(components.begin() + i);
			}
		}
	}
	template<typename T>
	T* GetComponent() {
		for (AComponent* component : components) {
			if (T* toGet = dynamic_cast<T*>(component)) {
				return toGet;
			}
		}
		return nullptr;
	}
};
