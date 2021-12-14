#include "TileManager.h"
#include <assert.h>

using namespace sf;
using namespace std;

TileManager* TileManager::m_s_Instance = nullptr;

TileManager::TileManager(){
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TileManager::GetTexture(string const& filename) {
	auto& m = m_s_Instance->m_Textures;

	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end()) {
		return keyValuePair->second;
	}
	else {
		auto& texture = m[filename];

		texture.loadFromFile(filename);

		return texture;
	}
}