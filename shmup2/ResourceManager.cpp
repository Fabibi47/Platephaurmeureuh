#pragma once
#include "ResourceManager.h"
#include <windows.h>

ResourceManager* ResourceManager::m_instance = nullptr;

ResourceManager* ResourceManager::getInstance() {
	if (!m_instance) {
		m_instance = new ResourceManager();
	}
	return m_instance;
}

sf::Texture* ResourceManager::LoadTexture(std::string texturePath) {
	if (!_textureCache.contains(texturePath)) {
		TCHAR buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, _countof(buffer));
		
		_textureCache[texturePath] = new sf::Texture(std::filesystem::path(buffer).parent_path().string() + "\\" + texturePath);
	}
	return _textureCache[texturePath];
}

sf::Font* ResourceManager::LoadFont(std::string fontPath) {
	if (!_fontCache.contains(fontPath)) {
		TCHAR buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, _countof(buffer));

		_fontCache[fontPath] = new sf::Font(std::filesystem::path(buffer).parent_path().string() + "\\" + fontPath);
	}
	return _fontCache[fontPath];
}