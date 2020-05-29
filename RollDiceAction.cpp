#include "RollDiceAction.h"
#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Grid* pGrid = pManager->GetGrid();
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	
	// -- If not ended, do the following --:
	if (!pGrid->GetEndGame())
		// 2- Generate a random number from 1 to 6 --> This step is done for you
	{
		Player* cPlayer = pGrid->GetCurrentPlayer();

		//We are in the Infinity War!
		if (!cPlayer->GetForbiddden())
		{
			srand((int)time(NULL)); // time is for different seed each run
			int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
			Output* pOut = pGrid->GetOutput();
			pGrid->PrintErrorMessage("Your dice number is: " + to_string(diceNumber)+"  ,Click to move..");
			// 3- Get the "current" player from pGrid
			// 4- Move the currentPlayer using function Move of class player
			cPlayer->Move(pGrid, diceNumber);
			// 5- Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
			// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
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
		pGrid->GetOutput()->PrintMessage("Game Over! ");
		pGrid->GetInput()->GetCellClicked();
	}
}

RollDiceAction::~RollDiceAction()
{
}
