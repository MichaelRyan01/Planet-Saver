#include "TileManager.h"
#include <assert.h>

using namespace sf;
using namespace std;
//m_s_Instance is a static varibale
//It is being declared null here
TileManager* TileManager::m_s_Instance = nullptr;

TileManager::TileManager(){
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TileManager::GetTexture(string const& filename) {
	//m_s_Instance is referencing m_Textires
	auto& m = m_s_Instance->m_Textures;
	//Iterator to hold the keyValuePair
	//It is being searched for as well using the filename
	auto keyValuePair = m.find(filename);

	//Checkking if a match has been found
	if (keyValuePair != m.end()) {
		//If so it will return a texture
		return keyValuePair->second;
	}
	else {
		//A new key will be created
		auto& texture = m[filename];
		//Loading the texture from the filename
		texture.loadFromFile(filename);

		return texture;
	}
}