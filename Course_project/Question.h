#include <string>

typedef unsigned uint;

class Question
{
    uint id;
    // ����� �������
    std::string text;  //questionText �� �����? ����� �������� �� ���� ��, ��� � ����������?
                       // ����� ����� ���������� ��������� questions[i].text ����� ����
public:
    uint getId();
};