#include "CardGampe.h"


int CardGampe::totalparticipants = 0;

int main()
{
	CardGampe *bridge = 0;
	CardGampe *blackjack = 0;
	CardGampe *solitaire = 0;
	CardGampe *poker = 0;

	bridge = new CardGampe(4);
	blackjack = new CardGampe(8);
	solitaire = new CardGampe(1);

	delete blackjack;
	delete bridge;

	poker = new CardGampe(5);
	delete solitaire;
	delete poker;

	return 0;
}