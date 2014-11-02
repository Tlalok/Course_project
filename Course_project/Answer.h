#include <string>
#include <fstream>

typedef unsigned uint;

class Answer
{
	static const uint TEXT_SIZE = 20;
    uint id;
    // ����� ������
    std::string text;    //answerText �� �����? ����� �������� �� ���� ��, ��� � ����������?
                         // ����� ����� ���������� ��������� answers[i].text ����� ����
public:
    uint getId();
	std::string getText();
	void setId(uint id);
	void setText(std::string text);
	friend std::fstream& operator>>(std::fstream& file, Answer& question);
	friend std::fstream& operator<<(std::fstream& file, Answer& question);
};