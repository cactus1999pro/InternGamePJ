#include"AnimationSprite.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"
AnimationSprite::AnimationSprite() : m_numFrames(0), m_currentFrame(0), m_frameTime(0.0f), m_currentFrameTime(0.0f), m_time(0.0f), m_speed(0.0f)
{

}
AnimationSprite::AnimationSprite(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture,
	int numFrames, float frameTime, GLfloat speed) : Sprite2D(model, shader, texture), m_numFrames(numFrames), m_currentFrame(0), m_frameTime(frameTime), m_currentFrameTime(0.0f), m_speed(speed)
{
	
	m_coin = std::make_shared<Sprite2D>(model, shader, texture);
	m_coin->Set2DPosition(rand() % 800 + 50, 50);
	m_coin->SetSize(70, 70);

	m_coin1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_coin1->Set2DPosition(rand() % 1200 + 600, 50);
	m_coin1->SetSize(70, 70);

	//m_enermy = std::make_shared<Sprite2D>(model, shader, texture);
	//m_enermy->Set2DPosition(150, 150);
	//m_enermy->SetSize(70, 70);
	//Init();
}
void AnimationSprite::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void AnimationSprite::Draw()
{
	m_coin->Draw();
	m_coin1->Draw();
	//m_enermy->Draw();
	
	
	if (m_pCamera == nullptr) return;
	glUseProgram(m_pShader->m_program);
	glBindBuffer(GL_ARRAY_BUFFER, m_pModel->GetVertexObject());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pModel->GetIndiceObject());

	GLuint iTempShaderVaribleGLID = -1;
	Matrix wvpMatrix;

	wvpMatrix = m_worldMatrix * m_pCamera->GetLookAtCameraMatrix();

	if (m_pTexture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_pTexture->Get2DTextureAdd());
		if (m_pShader->m_iTextureLoc[0] != -1)
			glUniform1i(m_pShader->m_iTextureLoc[0], 0);
	}
	else
	{
		iTempShaderVaribleGLID = -1;
		iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_color");
		if (iTempShaderVaribleGLID != -1)
			glUniform4f(iTempShaderVaribleGLID, m_color.x, m_color.y, m_color.z, m_color.w);
	}


	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_posL");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_POSITION);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_uv");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_UV);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_alpha");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, 1.0);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_wvpMatrix");
	if (iTempShaderVaribleGLID != -1)
		glUniformMatrix4fv(iTempShaderVaribleGLID, 1, GL_FALSE, wvpMatrix.m[0]);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_numFrames");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, m_numFrames);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_currentFrame");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, m_currentFrame);


	glDrawElements(GL_TRIANGLES, m_pModel->GetNumIndiceObject(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void AnimationSprite::Update(GLfloat deltatime)
{
	m_time += deltatime;
	Vector2 deltamove = Vector2(0, 1) * m_speed * deltatime;
	m_coin->Set2DPosition(m_coin->GetPosition().x + deltamove.x, m_coin->GetPosition().y + deltamove.y);
	
	m_coin1->Set2DPosition(m_coin1->GetPosition().x + deltamove.x, m_coin1->GetPosition().y + deltamove.y);
	
	//m_enermy->Set2DPosition(m_enermy->GetPosition().x + deltamove.x, m_enermy->GetPosition().y + deltamove.y);
	
	//animation handling

	m_currentFrameTime += deltatime;
	if (m_currentFrameTime >= m_frameTime)
	{
		m_currentFrame++;
		if (m_currentFrame >= m_numFrames)
		{
			m_currentFrame = 0;
		}
		m_currentFrameTime -= m_frameTime;
	}
	if (m_coin->GetPosition().y > Globals::screenHeight)
	{
		m_coin->Set2DPosition(rand() % 800 + 50, 100);
	}
	
	if (m_coin1->GetPosition().y > Globals::screenHeight)
	{
		m_coin1->Set2DPosition(rand() % 1200 + 600, 100);
	}

	//if (m_enermy->GetPosition().y > Globals::screenHeight)
	//{
		//m_enermy->Set2DPosition(rand() % 1200 + 50, 100);
	//}
}