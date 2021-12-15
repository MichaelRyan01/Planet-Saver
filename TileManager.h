#pragma once
#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include<SFML/Graphics.hpp>
#include<map>

using namespace sf;
using namespace std;

class TileManager {
public:
	TileManager();
	static Texture& GetTexture(string const& filename);

private:
	//The map container will hold related pairs
	//Of String and Textures
	map<string, Texture> m_Textures;
	//The only instance pointer
	static TileManager* m_s_Instance;
};
#endif // !TILEMANAGER_H
