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
	map<string, Texture> m_Textures;
	static TileManager* m_s_Instance;
};
#endif // !TILEMANAGER_H
