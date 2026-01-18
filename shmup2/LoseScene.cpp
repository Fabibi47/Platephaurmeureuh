#pragma once
#include <iostream>
#include "Engine.h"
#include "LoseScene.h"

LoseScene::LoseScene(Engine* engine) : Scene(engine), titleText(font), retryText(font), quitText(font) {
	titleText.setString("You Lose !");
	titleText.setCharacterSize(50);
	titleText.setFillColor(sf::Color::Yellow);
	sf::FloatRect titleBounds = titleText.getLocalBounds();
	titleText.setOrigin({ titleBounds.size.x / 2, titleBounds.size.y / 2 });
	sf::Vector2u windowSize = engine->getWindow()->getSize();
	sf::Vector2f windowSizef = sf::Vector2f{ (float)windowSize.x, (float)windowSize.y };
	titleText.setPosition({ windowSizef.x / 2, 200 });


	retryText.setString("Retry");
	retryText.setCharacterSize(30);
	retryText.setFillColor(sf::Color::Yellow);
	sf::FloatRect retryBounds = retryText.getLocalBounds();
	retryText.setOrigin({ retryBounds.size.x / 2, retryBounds.size.y / 2 });
	retryText.setPosition({ windowSizef.x / 2, 400 });


	quitText.setString("Quit");
	quitText.setCharacterSize(30);
	quitText.setFillColor(sf::Color::Yellow);
	sf::FloatRect quitBounds = quitText.getLocalBounds();
	quitText.setOrigin({ quitBounds.size.x / 2, quitBounds.size.y / 2 });
	quitText.setPosition({ windowSizef.x / 2, 500 });
}

void LoseScene::Update(float dt) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(*engine->getWindow());
	sf::Vector2f mousePosf = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
	if (retryText.getGlobalBounds().contains(mousePosf)) {
		retryText.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			setSwitch(true, 1);
		}
	}
	else {
		retryText.setFillColor(sf::Color::Yellow);
	}
	if (quitText.getGlobalBounds().contains(mousePosf)) {
		quitText.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			engine->getWindow()->close();
		}
	}
	else {
		quitText.setFillColor(sf::Color::Yellow);
	}
	Draw();
}


void LoseScene::Draw() {
	engine->getWindow()->setView(engine->getWindow()->getDefaultView());
	engine->getWindow()->draw(titleText);
	engine->getWindow()->draw(retryText);
	engine->getWindow()->draw(quitText);
}