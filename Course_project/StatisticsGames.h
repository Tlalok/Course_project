#include <vector>
//#include <unordered_map>
#include "Character.h"
#include "Probability.h"
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
    std::vector<Character> characters;
    // есть мысль вынести из класса персонажа статискику вопросов 
    // в поле этого класса в качетве хеш-таблицы
    // и также поступить с ответами, но я не знаю что лучше(
public:
	uint getNumberOfCharacters();
	uint getTimesCharacterPicked(uint);
	std::string getNameOfCharacter(uint);
	uint getNumberGames();
	Character getCharacter(uint);

    double getPBi(uint idQuestion, uint idAnswer);

    // сколько всего раз задавался вопрос
    uint getTimesOfAskingQuestion(uint idQuestion);
    // сколько раз давался ответ на вопрос
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);

};