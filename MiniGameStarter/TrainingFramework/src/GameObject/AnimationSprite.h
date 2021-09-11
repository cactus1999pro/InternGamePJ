#pragma once
#include<Sprite2D.h>

class AnimationSprite :
	public Sprite2D
{
public:
	AnimationSprite();
	AnimationSprite(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture,
		int numFrames, float frameTime, GLfloat speed);
	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
protected:
	int m_numFrames;
	int m_currentFrame;
	float m_frameTime;
	float m_currentFrameTime;
	std::shared_ptr<Sprite2D>	m_coin;
	std::shared_ptr<Sprite2D>	m_coin1;
	//std::shared_ptr<Sprite2D>	m_enermy;
	GLfloat m_time;
	GLfloat m_speed;

};