#pragma once
#include<Sprite2D.h>

class movingObj : public Sprite2D
{
public:
	movingObj();
	movingObj(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLfloat speed
		);
	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
protected:
	std::shared_ptr<Sprite2D>	m_bomb;
	std::shared_ptr<Sprite2D>	m_kunai;
	std::shared_ptr<Sprite2D>	m_bomb1;
	GLfloat m_time;
	GLfloat m_speed;
};