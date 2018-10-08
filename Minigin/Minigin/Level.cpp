#include "stdafx.h"
#include "Level.h"
#include <fstream>

Level::Level(const string& levelName): m_filename(levelName)
{
	LoadLevel();
}


Level::~Level()
{
	for (UINT i(0); i < m_Map.size(); i++) {
		for (UINT j(0); j <m_Map[i].size(); j++) {
			SafeDelete(m_Map[i][j]);
		}

	}
}

vector<vector<Map*>>& Level::GetMap()
{
	return m_Map;
}

void Level::LoadLevel()
{
	ifstream file("../Data/" + m_filename);
	string value;
	for (int i(0); i < 10; i++) {
		vector<Map*> theMap;
		for (int j(0); j < 15; j++) {
			getline(file, value, ',');
			if (value.size() > 1) {
				value = value.substr(1);
			}
			switch (value[0]) {
			case 'w':
				theMap.push_back(new Map(true, false, false, false, false));
				break;
			case 'p':
				theMap.push_back(new Map(false, true, false, false, false));
				break;
			case 'u':
				theMap.push_back(new Map(false, false, false, false, true));
				break;
			case 'k':
				theMap.push_back(new Map(false, false, true, false, false));
				break;
			case 'g':
				theMap.push_back(new Map(false, false, false, true, false));
				break;
			}
		}
		m_Map.push_back(theMap);
	}

}
