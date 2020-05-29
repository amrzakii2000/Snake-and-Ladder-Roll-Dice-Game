#pragma once
#include"Card.h"
class CardSix:public Card
{
public:
	CardSix(const CellPosition& cellposition);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSix();
};

