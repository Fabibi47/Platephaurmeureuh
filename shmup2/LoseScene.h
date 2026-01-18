#pragma once
#include "Scene.h"
#include "ResourceManager.h"

class LoseScene : public Scene
{
	ResourceManager* resources = ResourceManager::getInstance();
	sf::Font font = *resources->LoadFont("Heavitas.ttf");
	sf::Text titleText;
	sf::Text retryText;
	sf::Text quitText;
public:
	LoseScene(Engine* engine);
	void Update(float dt) override;
	void Draw();
};

