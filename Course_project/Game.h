#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"
#include <vector>
#include <map>
#include "Probability.h"

class Game
{
    StatisticsGames statisticsGames;
    // список всех вопросов
    std::vector<Question> questions;
    // список всех ответов
    std::vector<Answer> answers;
	//текущее кол-во заданных в этой игре вопросов // текущее количество можно получить из свойства вектора //это же private, придётся вызывать метод этого класса в котором будет вызываться метод класса вектор, норм разве7
                                                   // по идее нам делать этот метод не нужно, но если бы и пришлось мы бы в любом случае делали ли бы метод оавницы бы почти не было либо return numberQuestions либо return currentQustionsAnswers.size()
    // текущая последовательность вопросов и ответов которые дал пользователь
    std::vector<std::pair<uint, uint>> currentAnswers;
	// здесь должен быть какой-то массив вероятностей текущих для всех персонажей, насколько я понимаю
	// думаю да, тогда их проще будет вычислять
    // как вариант ассоциативный массив в котором вероятности хранятся по имени персонажа
	std::map<std::string, double> currentProbability;
public:
	Game();
	void calculate();
};