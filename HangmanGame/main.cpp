#include <iostream>
#include "Game.h"

using namespace std;


void Initialize();
void GetInput();
void Update(float deltaTime);
void Render();
void Shutdown();


bool g_exitGame = false;
Game g_game;

int main()
{
	Initialize();

	while (!g_exitGame)
	{
		GetInput();
		Update(0.0f);
		Render();
	}
	
	Shutdown();

	return 0;
}

void Initialize()
{
	g_game.OnInit();
}

void GetInput()
{
	char _letter;

	cout << "Podaj jakas litere: ";
	cin >> _letter;
	cout << endl;

	if (isalpha(_letter))
	{
		g_game.OnInput(_letter);
	}
	else
	{
		cout << "Musisz podac litere!" << endl << endl;
		GetInput();
	}
}

void Update(float deltaTime)
{
	g_exitGame = g_game.OnUpdate(deltaTime);
}

void Render()
{
	cout << g_game.OnRender();
}

void Shutdown()
{
	g_game.OnShutdown();
}
