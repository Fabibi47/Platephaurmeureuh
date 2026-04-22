#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Scene.h"
#include "Physics.h"

class Engine
{
	int currentScene = 0;
	int previousScene = 0;
	Physics* physics;
	sf::RenderWindow* window;
	std::vector<Scene*> scenes;
	sf::Clock clock;
public:
	Engine(Physics* physics);
	void Update();
	sf::RenderWindow* getWindow();
	void AddScene(Scene* scene);
	void SwitchScene(int index);
	Physics* getPhysics();
	int getCurrentScene();
	int getPreviousScene();
};