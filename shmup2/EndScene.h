#pragma once
#include "Scene.h"
#include "ResourceManager.h"

class EndScene : public Scene
{
	ResourceManager* resources = ResourceManager::getInstance();
	sf::Font font = *resources->LoadFont("Heavitas.ttf");
	sf::Text titleText;
	sf::Text returnText;
	sf::Text quitText;
public:
	EndScene(Engine* engine);
	void Update(float dt) override;
	void Draw();
};

