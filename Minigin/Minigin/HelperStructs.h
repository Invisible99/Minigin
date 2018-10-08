#pragma once
struct Map {
	Map(bool wall, bool pill, bool power, bool ghost, bool pacman) : isWall(wall), isPill(pill), isPowerUp(power), isGhost(ghost), isPacman(pacman) {

	}
	bool isWall;
	bool isPill;
	bool isPowerUp;
	bool isGhost;
	bool isPacman;
};