#include "CardNine.h"
#include "Player.h"
#include "Card.h"


CardNine::CardNine(const CellPosition pos, Grid* pGrid):Card(pos)
{
	cardNumber = 9;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter value to move player by when stopping on this card: ");
	move = pIn->GetInteger(pOut);
}
int CardNine::getcelltomove() const
{
	return move;
}
void CardNine::Apply(Grid* pGrid, Player *pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition pos2 = pPlayer->GetCurrentCell();
	pGrid->UpdatePlayerCell(pPlayer,move);
}


