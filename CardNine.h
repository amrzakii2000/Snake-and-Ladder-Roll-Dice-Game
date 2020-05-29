#pragma once
#include "Card.h"
#include "ApplicationManager.h"
class CardNine : public Card
{
	int move;//CellPosition pos3;
public:
	CardNine(const CellPosition pos, Grid* pGrid);
	int getcelltomove()const;
	void Apply(Grid* pGrid, Player *pPlayer);
};

