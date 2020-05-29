#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
Ladder* l = pGrid->GetNextLadder(pPlayer->GetCurrentCell());
	if (l)
	{
		pGrid->UpdatePlayerCell(pPlayer, l->GetPosition());
	}
}