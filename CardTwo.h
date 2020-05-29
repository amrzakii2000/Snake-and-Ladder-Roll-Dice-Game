#pragma once
#include "Card.h"

class CardTwo : public Card
{

	int walletAmount; // the wallet value to decrease from the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	int getwalletAmount();
	virtual ~CardTwo(); // A Virtual Destructor
};

