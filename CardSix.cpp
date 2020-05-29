#include "CardSix.h"
#include"Card.h"

CardSix::CardSix(const CellPosition& cellposition):Card(cellposition)
{
	cardNumber = 6;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, -(pPlayer->GetjustrolledDiceNum()));
}
CardSix::~CardSix()
{

}
