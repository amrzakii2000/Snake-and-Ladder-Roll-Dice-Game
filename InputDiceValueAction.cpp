#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();

	if (!pGrid->GetEndGame())
	{

		Player* cPlayer = pGrid->GetCurrentPlayer();
		if (!cPlayer->GetForbiddden())
		{
			Input* pIn = pGrid->GetInput();
			Output* pOut = pGrid->GetOutput();
			pOut->PrintMessage("Enter dice value:");
			dicenumber = pIn->GetInteger(pOut);
			while (dicenumber > 6 || dicenumber < 1)
			{
				pOut->PrintMessage("Enter correct dice value (between 1 and 6):");
				dicenumber = pIn->GetInteger(pOut);
			}
		}
		else
		{
			cPlayer->Move(pGrid, 0);
			cPlayer->SetForbidden(0);
			pGrid->AdvanceCurrentPlayer();


		}
	
	}
	else
	{
		pGrid->GetOutput()->PrintMessage("Game Over!");
		pGrid->GetInput()->GetCellClicked();
	}
}

void InputDiceValueAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	if (!pGrid->GetEndGame())
	{
		//We are in the Infinity War!
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("Your dice number is: " + to_string(dicenumber));
		Player* cPlayer = pGrid->GetCurrentPlayer();
		//Move the currentPlayer using function Move of class player
		cPlayer->Move(pGrid, dicenumber);
		//Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
}

InputDiceValueAction::~InputDiceValueAction()
{
}
