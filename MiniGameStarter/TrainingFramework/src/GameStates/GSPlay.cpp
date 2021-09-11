#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "AnimationSprite.h"
#include "ParallelBG.h"
#include "movingObj.h"
#include<cstdlib>
#include<ctime>
GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("seamlessBG1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<ParallelBG>(model, shader, texture, 100.0f);
	
	//bomb
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("bom1.tga");
	m_bomb = std::make_shared<movingObj>(model, shader, texture,100.0f);
	m_bomb1 = std::make_shared<movingObj>(model, shader, texture,160.0f);
	
	//character
	texture = ResourceManagers::GetInstance()->GetTexture("Attack__0001.tga");
	m_gameChar = std::make_shared<Sprite2D>(model, shader, texture);
	m_gameChar->Set2DPosition(50, Globals::screenHeight / 2+130);
	m_gameChar->SetSize(90, 90);

	
	//m_Enermy->Set2DPosition(Globals::screenWidth/2, Globals::screenHeight/2);
	//m_Enermy->SetSize(70, 70);
	
	
	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	
	
	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);

	m_score->Set2DPosition(Vector2(5, 25));

	//coin
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	texture = ResourceManagers::GetInstance()->GetTexture("coin1.tga");
	m_coin = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f, 140.0f);
	m_coin1 = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f, 100.0f);
	
	//kunai
	//shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	//texture = ResourceManagers::GetInstance()->GetTexture("kunai.tga");
	//m_kunai = std::make_shared<movingObj>(model, shader, texture, 150.0f);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true)
	{
		switch (key)
		{
		case 'A':
			keyPressed |= KEY_MOVE_LEFT;
			break;
		case 'D':
			keyPressed |= KEY_MOVE_RIGHT;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 'A':
			keyPressed ^= KEY_MOVE_LEFT;
			break;
		case 'D':
			keyPressed ^= KEY_MOVE_RIGHT;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	
	Vector3 Position = m_gameChar->GetPosition();
	if (keyPressed & KEY_MOVE_LEFT) {
			m_gameChar->Set2DPosition(Vector2(Position.x - 5, Position.y));
	}
	if (keyPressed & KEY_MOVE_RIGHT) {
			m_gameChar->Set2DPosition(Vector2(Position.x + 5, Position.y));
	}
	
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
		
		
	}
	m_coin->Update(deltaTime);
	m_coin1->Update(deltaTime);
	m_time += deltaTime;
	m_background->Update(deltaTime);
	m_bomb->Update(deltaTime);
	//m_kunai->Update(deltaTime);
	m_bomb1->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	
	m_gameChar->Draw();
	m_bomb->Draw();
	m_bomb1->Draw();
	m_coin->Draw();
	m_coin1->Draw();
	//m_kunai->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}