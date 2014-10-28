#include <string>
#include <fstream>

using namespace std;

typedef unsigned uint;

class Answer
{
	const uint TEXT_SIZE = 20;
    uint id;
    // ����� ������
    std::string text;    //answerText �� �����? ����� �������� �� ���� ��, ��� � ����������?
                         // ����� ����� ���������� ��������� answers[i].text ����� ����
public:
    uint getId();
	friend fstream& operator>>(fstream& file, Answer& question);
	friend fstream& operator<<(fstream& file, Answer& question);
};