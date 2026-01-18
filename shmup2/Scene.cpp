#pragma once
#include "Scene.h"
#include "Drawable.h"
#include "Damageable.h"
#include "Transformable.h"
#include "Attacker.h"
#include <iostream>
#include "Engine.h"
#include "ResourceManager.h"
#include "Text.h"
#include "Camera.h"
#include "RigidBody.h"

Scene::Scene(Engine* engine) : engine(engine) {};

void Scene::Update(float dt) {
	for (Entity* entity : entities) {
		if (!entity->isPendingDestroy()) {
			entity->Update(dt);
			if (Drawable* draw = entity->GetComponent<Drawable>()) {
				entity->Draw(*engine->getWindow());
			}
			if (Text* text = entity->GetComponent<Text>()) {
				text->Draw(*engine->getWindow());
			}
			if (activeCamera) {
				engine->getWindow()->setView(*activeCamera->getView());
			}
			else {
				engine->getWindow()->setView(engine->getWindow()->getDefaultView());
			}
		}
		else {
			AddEntityToRemove(entity);
		}
	}
}

void Scene::AddEntityToAdd(Entity* newEntity) {
	entitiesToAdd.push_back(newEntity);
}

void Scene::AddEntityToRemove(Entity* entity) {
	entitiesToRemove.push_back(entity);
}

void Scene::AddEntities() {
	for (Entity* newEntity : entitiesToAdd) {
		entities.push_back(newEntity);
	}
	entitiesToAdd.clear();
}

void Scene::RemoveEntities() {
	entities.erase(
		std::remove_if(entities.begin(), entities.end(),
			[](Entity* e) {
				return e->isPendingDestroy();
			}),
		entities.end()
	);
	entitiesToRemove.clear();
}

void Scene::RemoveEntity(Entity* entity) {
	for (int i = 0; i < entities.size(); i++) {
		if (entity == entities[i]) {
			entities.erase(entities.begin() + i);
			return;
		}
	}
}

std::vector<Entity*> Scene::getEntities() {
	return entities;
}

std::vector<Entity*> Scene::getEntitiesToRemove()
{
	return entitiesToRemove;
}

Engine* Scene::getEngine() {
	return engine;
}

void Scene::setActiveCamera(Camera* cam) {
	activeCamera = cam;
}

int Scene::ShouldSwitch() {
	if (isSwitched) {
		return nextScene;
	}
	return 0;
}

void Scene::setSwitch(bool should, int nextSceneIndex) {
	isSwitched = should;
	nextScene = nextSceneIndex;
}

std::vector<Entity*> Scene::getMap() {
	return map;
}

void Scene::setMap(std::vector<Entity*> newMap) {
	map = newMap;
}

void Scene::setPhysicsActive(bool isActive){
	for (Entity* entity : entities) {
		if (RigidBody* rb = entity->GetComponent<RigidBody>()) {
			b2BodyId bodyId = rb->getBody();
			if (isActive) {
				b2Body_Enable(bodyId);
			}
			else {
				b2Body_Disable(bodyId);
			}
		}
	}
}
