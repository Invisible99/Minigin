#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "TextComponent.h"
#include "Time.h"
#include "InputManager.h"
#include "Level.h"

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
private:
	GameObject* m_pFPS;
	Level* m_map;
	GameObject* m_pacman;
	GameObject* m_pacwoman;
	GameObject* m_score;
	
	float m_time;
};
