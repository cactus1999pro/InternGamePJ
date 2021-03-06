#include"movingObj.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"
#include "Sprite2D.h"
#include<cstdlib>
#include<ctime>



movingObj::movingObj() : m_time(0.0f), m_speed(0.0f)
{

}
movingObj::movingObj(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLfloat speed) : Sprite2D( model, shader, texture), 
m_time(0.0f) ,m_speed(speed)
{
	m_bomb = std::make_shared<Sprite2D>(model, shader, texture);
	m_bomb->Set2DPosition(rand() % 1200 + 400, 50);
	m_bomb->Set2DPosition(Globals::screenWidth / 2, 50);
	m_bomb->SetSize(70, 70);
	

	m_bomb1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_bomb1->Set2DPosition(rand() % 800 + 50, 50);
	m_bomb1->Set2DPosition(Globals::screenWidth / 2, 50);
	m_bomb1->SetSize(70, 70);


	//m_kunai = std::make_shared<Sprite2D>(model, shader, texture);
	//m_kunai->Set2DPosition(rand() % 600 + 50, 50);
	//m_kunai->Set2DPosition(Globals::screenWidth / 2, 50);
	//m_kunai->SetSize(70, 70);
	Init();
	
	
}
void movingObj::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void movingObj::Draw()
{
	m_bomb->Draw();
	//m_kunai->Draw();
	m_bomb1->Draw();
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

	


	glDrawElements(GL_TRIANGLES, m_pModel->GetNumIndiceObject(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	

}

void movingObj::Update(GLfloat deltatime)
{
	
	
	
	m_time += deltatime;
	Vector2 deltamove = Vector2(0, 1) * m_speed * deltatime;

	m_bomb->Set2DPosition(m_bomb->GetPosition().x + deltamove.x, m_bomb->GetPosition().y + deltamove.y);
	
		if (m_bomb->GetPosition().y > Globals::screenHeight)
		{
			//srand(time(NULL));
			m_bomb->Set2DPosition(rand() % 1200 + 400, 50);
			
			
		}
		//m_kunai->Set2DPosition(m_kunai->GetPosition().x + deltamove.x, m_kunai->GetPosition().y + deltamove.y);

		//if (m_kunai->GetPosition().y > Globals::screenHeight)
		//{
			//srand(time(NULL));
			//m_kunai->Set2DPosition(rand() % 1280 + 50, 50);


		//}

		m_bomb1->Set2DPosition(m_bomb1->GetPosition().x + deltamove.x, m_bomb1->GetPosition().y + deltamove.y);

		if (m_bomb1->GetPosition().y > Globals::screenHeight)
		{

			//srand(time(NULL));
			m_bomb1->Set2DPosition(rand() % 800 + 50, 50);


		}
}