#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"

class Game
{
    StatisticsGames statisticsGames;
    // список все вопросов
    std::vector<Question> questions;
    // список всех ответов
    std::vector<Answer> answers;
	//текущее кол-во заданных в этой игре вопросов // текущее количество можно получить из свойства вектора //это же private, придётся вызывать метод этого класса в котором будет вызываться метод класса вектор, норм разве7
    // текущая последовательность вопросов и ответов которые дал пользователь
    std::vector<std::pair<unsigned int, unsigned int>> currentQustionsAnswers;
	// здесь должен быть какой-то массив вероятностей текущих для всех персонажей, насколько я понимаю
	// думаю да, тогда их проще будет вычислять
    // как вариант ассоциативный массив в котором вероятности хранятся по имени персонажа
    // std::map<std::string, double> currentProbability;

    const double normalizingCoefficient = 0.95;
};