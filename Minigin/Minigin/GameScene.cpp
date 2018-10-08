#include "stdafx.h"
#include "GameScene.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "ComponentIncluder.h"
#include "Command.h"
#include "Level.h"
GameScene::GameScene() : Scene("TheGame")
{
}


GameScene::~GameScene()
{
	SafeDelete(m_map);
}

void GameScene::Initialize()
{
	
	m_map = new Level("Level.csv");
	
	m_pacman = new GameObject();
	m_pacwoman = new GameObject();
	m_score = new GameObject();
	GameObject* ghostManagerOBJ = new GameObject();
	GhostManagerComponent* ghostManagerCom = new GhostManagerComponent();
	ghostManagerOBJ->AddComponent(ghostManagerCom);
	Add(ghostManagerOBJ);

	//End screen, not adding them to the scene here because it needs to be on top of everything
	GameObject* endGameScreen = new GameObject();
	endGameScreen->GetTransform()->SetPosition(255, 200);
	endGameScreen->AddComponent(new TextComponent("Game end", 70));
	endGameScreen->SwitchActive();

	GameObject* endGame = new GameObject();
	EndGameComponent* endGameCom = new EndGameComponent(endGameScreen);
	endGameCom->AddPlayer();
	endGame->AddComponent(endGameCom);

	int ghost = 0;
	vector<vector<Map*>> map = m_map->GetMap();
	glm::vec2 pos (0, 0);
	for (UINT i(0); i < map.size(); i++) {
		for (UINT j(0); j < map[i].size(); j++) {
			if (map[i][j]->isWall) {
				GameObject* wall = new GameObject();
				wall->GetTransform()->SetPosition(pos);
				wall->AddComponent(new SpriteComponent("Wall.png"));
				Add(wall);
			}
			if (map[i][j]->isPill) {
				GameObject* pill = new GameObject();
				pill->GetTransform()->SetPosition(pos);
				pill->AddComponent(new PillComponent(map[i][j], m_pacman));
				pill->AddComponent(new SpriteComponent("Pill.png"));
				Add(pill);
			}
			if (map[i][j]->isPowerUp) {
				GameObject* powerUp = new GameObject();
				powerUp->GetTransform()->SetPosition(pos);
				powerUp->AddComponent(new SpriteComponent("Powerup.png"));
				powerUp->AddComponent(new PowerupComponent(map[i][j], m_pacman, ghostManagerOBJ));
				Add(powerUp);
			}
			if (map[i][j]->isGhost) {
				
				GameObject* ghostObj = new GameObject();
				ghostObj->GetTransform()->SetPosition(pos);
				if (ghost == 0) ghostObj->AddComponent(new SpriteComponent("YellowGhost.png"));
				if (ghost == 1) ghostObj->AddComponent(new SpriteComponent("RedGhost.png"));
				if (ghost == 2) ghostObj->AddComponent(new SpriteComponent("BlueGhost.png"));
				if (ghost == 3) ghostObj->AddComponent(new SpriteComponent("GreenGhost.png"));				
				ghostObj->AddComponent(new MovementComponent(map, i, j));
				ghostObj->AddComponent(new GhostComponent(m_pacman, m_pacwoman));
				ghost++;
				ghostManagerCom->AddGhost(ghostObj);
			}
			if (map[i][j]->isPacman) {
				m_pacman->GetTransform()->SetPosition(pos);
				m_pacman->AddComponent(new InputComponent(0));
				m_pacman->AddComponent(new SpriteComponent("Pacman.png"));
				m_pacman->AddComponent(new PacmanComponent(m_score, endGame));
				m_pacman->AddComponent(new MovementComponent(map, i, j));

				m_pacwoman->GetTransform()->SetPosition(pos);
				m_pacwoman->AddComponent(new InputComponent(1));
				m_pacwoman->AddComponent(new SpriteComponent("Pacwoman.png"));
				m_pacwoman->AddComponent(new PacmanComponent(m_score, endGame));
				m_pacwoman->AddComponent(new MovementComponent(map, i, j));				
							
			}
			pos.x += 50;
		}
		pos.x = 0;
		pos.y += 50;
	}
	
	m_pFPS = new GameObject();
	m_pFPS->AddComponent(new TextComponent(to_string(Time::GetInstance().GetFPS()), 36));
	Add(m_pFPS);

	m_score->AddComponent(new TextComponent("0", 36));
	m_score->GetTransform()->SetPosition(375, 0);
	Add(m_score);

	//Pacman lives
	LiveManagerComponent* lives = new LiveManagerComponent();
	float x = 0;
	float y = 9 * 50.f;
	for (int k(0); k < 3; k++) {
		GameObject* live = new GameObject();
		live->GetTransform()->SetPosition(x, y);
		live->AddComponent(new SpriteComponent("Pacman.png"));
		Add(live);
		lives->AddLive(live);
		x += 50.f;
	}
	m_pacman->AddComponent(lives);

	//pacwoman lives
	LiveManagerComponent* livesW = new LiveManagerComponent();
	x = 12 * 50.f;
	y = 9 * 50.f;
	for (int k(0); k < 3; k++) {
		GameObject* live = new GameObject();
		live->GetTransform()->SetPosition(x, y);
		live->AddComponent(new SpriteComponent("Pacwoman.png"));
		live->SwitchActive();
		Add(live);
		livesW->AddLive(live);
		x += 50.f;
	}
	m_pacwoman->AddComponent(livesW);
	m_pacwoman->SwitchActive();
	//Adding at the end so they are on top
	for (auto g : ghostManagerCom->GetGhosts()) {
		Add(g);
	}

	Add(m_pacman);
	Add(m_pacwoman);


	Add(endGameScreen);
	Add(endGame);
}

void GameScene::Update()
{
	m_pFPS->GetComponent<TextComponent>()->SetText(to_string((int)Time::GetInstance().GetFPS()));
}

void GameScene::Render()
{
}
