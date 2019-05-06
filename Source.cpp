#include <iostream>

using namespace std;

#include "olcConsoleGameEngine.h"

class game_class : public olcConsoleGameEngine
{
public:
	game_class()
	{
		m_sAppName = L"Game";
	}

private:
	float x;
	float y;
	float xspeed;
	float yspeed;
	float p1;
	float p2;

protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		//inicializar variaveis
		x = 150;
		y = 150;
		xspeed = 200;
		yspeed = 0;
		p1 = 150;
		p2 = 150;

		return true;
	}

	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		//Desenhos

		//Desenho do fundo
		Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ', BG_BLACK);
		//Desenho da bola
		FillCircle( (int)x, (int)y, 4, PIXEL_SOLID, FG_WHITE);
		//Desenho player 1
		Fill(0, (int)p1, 10, (int)p1+20, PIXEL_SOLID, FG_WHITE);
		//Desenho player 2
		Fill(ScreenWidth()-10, (int)p2, ScreenWidth(), (int)p2+20, PIXEL_SOLID, FG_WHITE);

		//teclas player1
		if (m_keys[VK_UP].bHeld)
			p1 -= 300.0f * fElapsedTime;
		if (m_keys[VK_DOWN].bHeld)
			p1 += 300.0f * fElapsedTime;
		//teclas player2
		if (m_keys[0x57].bHeld)
			p2 -= 300.0f * fElapsedTime;
		if (m_keys[0x53].bHeld)
			p2 += 300.0f * fElapsedTime;

		//movimento da bola
		y += yspeed * fElapsedTime;
		x += xspeed * fElapsedTime;

		//fronteiras do ecrã
		//esquerda
		if (x < 4)
		{
			xspeed = -xspeed;
			x = 4;
		}
		//direita
		if (x >= m_nScreenWidth - 5)
		{
			xspeed = -xspeed;
			x = (float)m_nScreenWidth - 5;
		}
		//cima
		if (y < 4)
		{
			y = 4;
			yspeed = -yspeed;
		}
		//baixo
		if (y >= m_nScreenHeight - 5)
		{
			y = (float)m_nScreenHeight - 5;
			yspeed = -yspeed;
		}

		return true;
	}
};


int main()
{

	game_class game;
	game.ConstructConsole(400, 300, 2, 2);
	game.Start();

	return 0;
}