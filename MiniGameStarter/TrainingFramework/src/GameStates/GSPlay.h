#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class AnimationSprite;
class ParallelBG;
class movingObj;
class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<ParallelBG>	m_background;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Sprite2D>	m_gameChar;
	std::shared_ptr<AnimationSprite>	m_coin;
	GLfloat m_time;
	std::shared_ptr<movingObj> m_bomb;
	std::shared_ptr<movingObj> m_bomb1;
	std::shared_ptr<movingObj> m_kunai;
	std::shared_ptr<AnimationSprite>	m_coin1;
};

