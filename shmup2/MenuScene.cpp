#pragma once
#include <iostream>
#include "MenuScene.h"
#include "Engine.h"

MenuScene::MenuScene(Engine* engine) : Scene(engine), titleText(font), playText(font), quitText(font) {
	titleText.setString("Platephaurmeureuh");
	titleText.setCharacterSize(50);
	titleText.setFillColor(sf::Color::Yellow);
	sf::FloatRect titleBounds = titleText.getLocalBounds();
	titleText.setOrigin({ titleBounds.size.x / 2, titleBounds.size.y / 2 });
	sf::Vector2u windowSize = engine->getWindow()->getSize();
	sf::Vector2f windowSizef = sf::Vector2f{ (float)windowSize.x, (float)windowSize.y };
	titleText.setPosition({ windowSizef.x / 2, 200 });


	playText.setString("Play");
	playText.setCharacterSize(30);
	playText.setFillColor(sf::Color::Yellow);
	sf::FloatRect playBounds = playText.getLocalBounds();
	playText.setOrigin({ playBounds.size.x / 2, playBounds.size.y / 2 });
	playText.setPosition({ windowSizef.x / 2, 400 });


	quitText.setString("Quit");
	quitText.setCharacterSize(30);
	quitText.setFillColor(sf::Color::Yellow);
	sf::FloatRect quitBounds = quitText.getLocalBounds();
	quitText.setOrigin({ quitBounds.size.x / 2, quitBounds.size.y / 2 });
	quitText.setPosition({ windowSizef.x / 2, 500 });
}

void MenuScene::Update(float dt) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(*engine->getWindow());
	sf::Vector2f mousePosf = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
	if (playText.getGlobalBounds().contains(mousePosf)) {
		playText.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			setSwitch(true, 1);
		}
	}
	else {
		playText.setFillColor(sf::Color::Yellow);
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

void MenuScene::Draw() {
	engine->getWindow()->setView(engine->getWindow()->getDefaultView());
	engine->getWindow()->draw(titleText);
	engine->getWindow()->draw(playText);
	engine->getWindow()->draw(quitText);
}