#pragma once
#include <string>
#include <vector>


class Game
{
	enum class GameState
	{
		START,
		UPDATE,
		FINISH
	};

public:
	void OnInit();
	void OnInput(char letter);
	bool OnUpdate(float deltaTime);
	std::string OnRender();
	void OnShutdown();

private:
	std::string m_word;
	std::vector<std::string> m_wordsPool = { "kolor", "silnik", "wzorzec", "silnie", "kanapka" };
	std::vector<bool> m_guessedLetters;
	std::vector<char> m_enteredLetters;
	int m_guessed = 0;
	int m_missed = 0;
	GameState m_gameState = GameState::START;
	std::string m_hangmanPictures[7] = {
		"  +---+\n  |   | \n      | \n      | \n      | \n      | \n=========",
		"  +---+\n  |   | \n  O   | \n      | \n      | \n      | \n=========",
		"  +---+\n  |   | \n  O   | \n  |   | \n      | \n      | \n=========",
		"  +---+\n  |   | \n  O   | \n /|   | \n      | \n      | \n=========",
		"  +---+\n  |   | \n  O   | \n /|\\  | \n      | \n      | \n=========",
		"  +---+\n  |   | \n  O   | \n /|\\  | \n /    | \n      | \n=========",
		"  +---+\n  |   | \n  O   | \n /|\\  | \n / \\  | \n      | \n========="
	};
};