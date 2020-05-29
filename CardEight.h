#pragma once
#include"Card.h"

class CardEight:public Card
{
	
public:
	CardEight(const CellPosition& cellposition);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight();
};

