#include "Game.h"
#include <cstdlib>
#include <ctime>

void Game::OnInit()
{
	m_guessedLetters.clear();
	srand(std::time(NULL));
	int randomIndex = rand() % m_wordsPool.size();
	m_word = m_wordsPool[randomIndex];

	m_gameState = GameState::START;
}

void Game::OnInput()
{

}

bool Game::OnUpdate(float deltaTime)
{




	return false;
}

std::string Game::OnRender()
{
	std::string output;

	return output;
}

void Game::OnShutdown()
{
	m_guessedLetters.clear();

	m_gameState = GameState::FINISH;
}
