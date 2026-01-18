#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Camera.h"

class Engine;
class Scene
{
	bool isSwitched = false;

	Camera* activeCamera = nullptr;

	std::vector<Entity*> entities;
	std::vector<Entity*> entitiesToAdd;
	std::vector<Entity*> entitiesToRemove;
	std::vector<Entity*> background = {};
	std::vector<Entity*> map = {};

protected:
	Engine* engine;
	int nextScene = 0;

public:
	Scene(Engine* engine);
	virtual void Update(float dt);
	void AddEntityToAdd(Entity* newEntity);
	void AddEntityToRemove(Entity* entity);
	void AddEntities();
	void RemoveEntities();
	void RemoveEntity(Entity* entity);
	int ShouldSwitch();
	void setSwitch(bool, int);
	std::vector<Entity*> getMap();
	void setMap(std::vector<Entity*> newMap);
	void setPhysicsActive(bool isActive);
	
	std::vector<Entity*> getEntities();
	std::vector<Entity*> getEntitiesToRemove();
	Engine* getEngine();
	void setActiveCamera(Camera* cam);
};

