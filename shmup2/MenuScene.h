#pragma once
#include "Scene.h"
#include "ResourceManager.h"

class MenuScene : public Scene
{
	ResourceManager* resources = ResourceManager::getInstance();
	sf::Font font = *resources->LoadFont("Heavitas.ttf");
	sf::Text titleText;
	sf::Text playText;
	sf::Text quitText;
public:
	MenuScene(Engine* engine);
	void Update(float dt) override;
	void Draw();
};

