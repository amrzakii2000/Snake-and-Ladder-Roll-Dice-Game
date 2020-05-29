#include "CardFive.h"
CardFive::CardFive(const CellPosition& cellposition) :Card(cellposition)
{
	cardNumber = 5;
	
}
void CardFive::ReadCardParameters(Grid* pGrid)
{
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	
	Card::Apply(pGrid,pPlayer);
	pPlayer->Move(pGrid, pPlayer->GetjustrolledDiceNum());
}

CardFive::~CardFive()
{

}
