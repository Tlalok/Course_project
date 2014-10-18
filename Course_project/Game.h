#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"

class Game
{
    StatisticsGames statisticsGames;
    // ������ ��� ��������
    std::vector<Question> questions;
    // ������ ���� �������
    std::vector<Answer> answers;
    // ������� ������������������ �������� � ������� ������� ��� ������������
    std::vector<std::pair<unsigned int, unsigned int>> currentQustionsAnswers;
};