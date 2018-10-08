#pragma once
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>

class Level
{
public:
	Level(const string& levelName);
	~Level();

	vector<vector<Map*>>& GetMap();
private:
	vector<vector<Map*>> m_Map;
	string m_filename;
	void LoadLevel();
};

