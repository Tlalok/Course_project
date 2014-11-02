//#include <unordered_map>
#include "Character.h"
#include <string>


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
	void addAnswer(StatisticsAnswer& toAdd);
	bool isCharacterExist(std::string name);
	void addQuestion(StatisticsQuestion& toAdd);
	void addCharacter(Character& toAdd);
	void checkCharactersStatistics(Vector<Question>& questions, Vector<Answer>& answers);
	bool charactersIsEmpty();
	uint getNumberOfCharacters();
	uint getTimesCharacterPicked(uint);
	std::string getNameOfCharacter(uint);
	uint getNumberGames();
	Character getCharacter(uint);

    //возвращает вероятность того что будет дан указанный ответ
    double getPBi(uint idQuestion, uint idAnswer);

    // P(Bj|Ai)
    double getPBjAi(uint idCharater, uint idQuestion, uint idAnswer);

	//P(Ai)
	double getPAi(uint n);

	friend std::fstream& operator>>(std::fstream& file, StatisticsGames& question);
	friend std::fstream& operator<<(std::fstream& file, StatisticsGames& question);
};