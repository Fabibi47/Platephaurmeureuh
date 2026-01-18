#pragma once
#include "Text.h"
#include "Entity.h"
#include "Transformable.h"

Text::Text(Entity* parent, std::string text, sf::Font font, int size, sf::Color color) : AComponent(parent), text(font)
{
	this->text.setString(text);
	this->text.setCharacterSize(size);
	this->text.setFillColor(color);
}

void Text::Draw(sf::RenderWindow& window) const {
	sf::RenderStates rs = sf::RenderStates::Default;
	rs.transform *= parent->GetComponent<Transformable>()->getTransform();
	window.draw(text, rs);
}

sf::Text Text::getText()
{
	return text;
}

void Text::setText(sf::Text newText)
{
	text = newText;
}

std::string Text::getString()
{
	return text.getString();
}

void Text::setString(std::string newString)
{
	text.setString(newString);
}

std::string Text::getFont()
{
	return fontPath;
}

void Text::setFont(sf::Font& newFont, std::string fontPath)
{
	this->fontPath = fontPath;
	text.setFont(newFont);
}

int Text::getSize() {
	return text.getCharacterSize();
}

void Text::setSize(int newSize) {
	text.setCharacterSize(newSize);
}

sf::Color Text::getColor() {
	return text.getFillColor();
}

void Text::setColor(sf::Color newColor) {
	text.setFillColor(newColor);
}