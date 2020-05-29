#include "CardEight.h"
CardEight::CardEight(const CellPosition& cellposition):Card(cellposition)
{
	cardNumber = 8;
	
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pPlayer->SetForbidden(1);
}
CardEight::~CardEight()
{

}
