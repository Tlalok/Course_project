#include "Character.h"

//������ ��� ����� �� ������������� ������ ��� P(Ai), ������� �� �������� � ������� ����

class Probability
{
	int characterId;
	double PAi;
	double fullProbability;
public:
	const double normalizingCoefficient = 0.95;
	Probability(Character, uint);
	double getPAi();
	double getFullProbability();
	void setFullProbability(double);
};