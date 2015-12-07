#include "CardGampe.h"

#include <iostream>
using namespace std;

CardGampe::CardGampe(int p)
{
	players = p;
	totalparticipants += p;
	cout << p << " players have started a new game. there are now " << totalparticipants << " players in total" << endl;
}


CardGampe::~CardGampe(void)
{
}
