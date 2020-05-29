#include "Ladder.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}




void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	pGrid->GetOutput()->PrintMessage("You have reached a ladder. Click to continue ...");
	pGrid->GetInput()->GetCellClicked();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}

bool  Ladder::IsOverLapping(GameObject* pNew) const
{
	Ladder* pNewLadder = dynamic_cast<Ladder*>(pNew);
	if (pNewLadder)
	{
		if ((pNewLadder->position.GetCellNum() >= this->position.GetCellNum()&& pNewLadder->position.GetCellNum() <= this->endCellPos.GetCellNum()) || (pNewLadder->position.GetCellNum() <= this->position.GetCellNum()&& pNewLadder->endCellPos.GetCellNum() >= this->position.GetCellNum()))
		{
			return true;
		}
	}
	return false;
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
