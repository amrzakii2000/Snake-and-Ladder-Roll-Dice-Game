#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos):GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
}
bool  Snake::IsOverLapping(GameObject* pNew) const
{
	Snake* pNewSnake = dynamic_cast<Snake*>(pNew);
	if (pNewSnake)
	{
		if ((pNewSnake->position.GetCellNum() >= this->position.GetCellNum()&& pNewSnake->endCellPos.GetCellNum() < this->position.GetCellNum()) || (pNewSnake->position.GetCellNum() >= this->endCellPos.GetCellNum()&& pNewSnake->position.GetCellNum() <= this->position.GetCellNum()))
		{
			return true;
		}
	}
	return false;
}
void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
 }

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->GetOutput()->PrintMessage("You have reached a snake. Click to continue ...");
	pGrid->GetInput()->GetCellClicked();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
 }

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{

}