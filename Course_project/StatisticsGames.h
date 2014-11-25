#pragma once
//#include <unordered_map>
#include "Character.h"
#include "include.h"


class StatisticsGames
{
    // общее число сыгранных игр
    // не знаю стоит ли его хранить или
    // просто добавим метод вычисляющий его как    //куда добавим?сюда?
    // сумму того сколько раз был загадан каждый   // да, сюда, или же просто оставим это поле
    // персонаж
    uint numberGames;
    // список персонажей
    Vector<Character> characters;
    // есть мысль вынести из класса персонажа статискику вопросов 
    // в поле этого класса в качетве хеш-таблицы
    // и также поступить с ответами, но я не знаю что лучше(
    // сколько всего раз задавался вопрос
    uint getTimesOfAskingQuestion(uint idQuestion);
    // сколько раз давался ответ на вопрос
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
public:
    StatisticsGames();
    StatisticsGames(StatisticsGames &StatisticsGames);
	void addAnswer(StatisticsAnswer& toAdd);
	uint isCharacterExist(std::string name);
	void addQuestion(StatisticsQuestion& toAdd);
	void addCharacter(Character& toAdd);
	void checkCharactersStatistics(Vector<Question>& questions, Vector<Answer>& answers);
	bool charactersIsEmpty();
	uint getNumberOfCharacters();
	uint getTimesCharacterPicked(uint idCharacter);
	std::string getNameOfCharacter(uint idCharacter);
	uint getNumberGames();
	Character getCharacter(uint idCharacter);
    Character getCharacterById(uint id);
	Vector <Character>& getCharacters();

    //возвращает вероятность того что будет дан указанный ответ
    double getPBi(uint idQuestion, uint idAnswer);

    // P(Bj|Ai)
    double getPBjAi(uint idCharater, uint idQuestion, uint idAnswer);

	//P(Ai)
	double getPAi(uint idCharacter);

	friend std::istream& operator>>(std::istream& file, StatisticsGames& statisticsGames);
	friend std::ostream& operator<<(std::ostream& file, StatisticsGames& statisticsGames);

    StatisticsGames& operator=(StatisticsGames toCopy);
	void incNumberGames();
	void characterGuessed(uint idCharacter, Vector<std::pair<uint, uint>>& currentAnswers);
};