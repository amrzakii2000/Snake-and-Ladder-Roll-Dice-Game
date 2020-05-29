#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Snake* s = pGrid->GetNextSnake(pPlayer->GetCurrentCell());
	if (s)
	{
		pGrid->UpdatePlayerCell(pPlayer, s->GetPosition());
	}
}