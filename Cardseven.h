#pragma once
#include "card.h"
class Cardseven :
	public Card
{
public:
	Cardseven(const CellPosition & pos); // A Constructor takes card position
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~Cardseven();
};

