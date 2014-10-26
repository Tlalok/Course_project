#include "Character.h"

//создал это чтобы не пересчитывать каждый раз P(Ai), которая не меняется в течении игры

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