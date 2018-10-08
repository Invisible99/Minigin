#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)
#include "BaseComponent.h"
#include "Level.h"
#include "Time.h"
class MovementComponent : public BaseComponent
{

public:
	enum MOVE {
		NONE,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	MovementComponent(vector<vector<Map*>> map, int i, int j);
	void SetMovement(MOVE move);
	vector<vector<Map*>> GetMap();
	Map* GetPlace();
	int GetI();
	void SetI(int i);
	int GetJ();
	void SetJ(int j);
	~MovementComponent();

protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
private:
	int m_iPlace;
	int m_jPlace;
	bool m_wallNotFound;
	float m_speed;
	glm::vec2 m_velocity;
	vector<vector<Map*>> m_Map;
	MOVE m_currentMovement;
};

