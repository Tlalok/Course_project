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
    // текущая последовательность вопросов и ответов которые дал пользователь
    std::vector<std::pair<unsigned int, unsigned int>> currentQustionsAnswers;
};