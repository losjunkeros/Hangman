#include "Game.h"
#include <cstdlib>
#include <ctime>

void Game::OnInit()
{
	m_gameState = GameState::START;

	m_guessedLetters.clear();
	m_enteredLetters.clear();
	m_counter = 0;

	srand(std::time(NULL));
	int randomIndex = rand() % m_wordsPool.size();
	m_word = m_wordsPool[randomIndex];

	for (int i = 0; i < m_word.size(); ++i)
	{
		m_guessedLetters.push_back(false);
	}
}

void Game::OnInput(char letter)
{
	m_enteredLetters.push_back(letter);
}

bool Game::OnUpdate(float deltaTime)
{
	m_gameState = GameState::UPDATE;

	for (int i = 0; i < m_word.size(); ++i)
	{
		if (m_word[i] == m_enteredLetters[m_enteredLetters.size() - 1])
		{
			m_guessedLetters[i] = true;
			m_counter++;
		}
	}

	if (m_counter == m_word.size())
	{
		return true;
	}

	return false;
}

std::string Game::OnRender()
{
	std::string output;

	return output;
}

void Game::OnShutdown()
{
	m_gameState = GameState::FINISH;

	m_guessedLetters.clear();
	m_enteredLetters.clear();
}
