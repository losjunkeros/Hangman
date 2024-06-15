#include "Game.h"
#include <cstdlib>
#include <ctime>

void Game::OnInit()
{
	m_gameState = GameState::START;

	m_guessedLetters.clear();
	m_enteredLetters.clear();
	m_guessed = 0;
	m_missed = 0;

	srand(std::time(NULL));
	int randomIndex = rand() % m_wordsPool.size();
	m_word = m_wordsPool[randomIndex];

	for (int i = 0; i < m_word.size(); ++i)
	{
		m_word[i] = toupper(m_word[i]);
		m_guessedLetters.push_back(false);
	}
}

void Game::OnInput(char letter)
{
	m_enteredLetters.push_back(toupper(letter));
}

bool Game::OnUpdate(float deltaTime)
{
	m_gameState = GameState::UPDATE;

	int _missedCounter = 0;

	for (int i = 0; i < m_word.size(); ++i)
	{
		if (m_word[i] == m_enteredLetters[m_enteredLetters.size() - 1])
		{
			m_guessedLetters[i] = true;
			m_guessed++;
		}
		else
		{
			_missedCounter++;
		}
	}

	if (_missedCounter == m_word.size())
	{
		m_missed++;
	}

	if ((m_guessed == m_word.size()) || (m_missed >= 7))
	{
		return true;
	}

	return false;
}

std::string Game::OnRender()
{
	std::string _output = "";

	for (int i = 0; i < m_guessedLetters.size(); ++i)
	{
		if (m_guessedLetters[i] == true)
		{
			_output.operator+=(m_word[i]);
			_output.operator+=(" ");
		}
		else
		{
			_output.operator+=("_ ");
		}
	}

	_output.operator+=("\n\n");

	_output.operator+=("Uzyte dotychczas litery:\n");

	for (int i = 0; i < m_enteredLetters.size(); ++i)
	{
		_output.operator+=(m_enteredLetters[i]);
		_output.operator+=(" ");
	}

	if (m_guessed == m_word.size())
	{
		_output.operator+=("\n\n\n\nGRATULACJE !!! WYGRALES !!!\n\n");
		return _output;
	}

	if (m_missed >= 7)
	{
		_output.operator+=("\n\n\n\nPRZEGRALES :(\n\n");
		return _output;
	}

	_output.operator+=("\n\n\n\n");

	return _output;
}

void Game::OnShutdown()
{
	m_gameState = GameState::FINISH;

	m_wordsPool.clear();
	m_guessedLetters.clear();
	m_enteredLetters.clear();
}
