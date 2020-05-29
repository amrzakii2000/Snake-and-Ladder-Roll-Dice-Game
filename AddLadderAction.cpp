#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition TempstartPos;
	CellPosition TempendPos;


	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	TempstartPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	TempendPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters

	bool flag_V = true;
	if ((TempstartPos.HCell() == TempendPos.HCell()) && (TempstartPos.VCell() <= TempendPos.VCell()))
	{
		pGrid->PrintErrorMessage("End cell cannot be smaller than or equal start cell ! Click to continue ...");
		flag_V = false;
	}
	if (TempstartPos.HCell() != TempendPos.HCell())
	{
		pGrid->PrintErrorMessage("End cell and start cell are not in the same column ! Click to continue ...");
		flag_V = false;
	}
	bool flag = (TempstartPos.IsValidCell() && TempendPos.IsValidCell());
	if (!flag)
	{
		pGrid->PrintErrorMessage("Invalid operation ! Click to continue ...");
		flag_V = false;
	}

	if (flag_V)    // If all is valid
	{
		startPos = TempstartPos;
		endPos = TempendPos;
	}
	else
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		endPos.SetHCell(-1);
		endPos.SetVCell(-1);
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (pGrid->IsOverLapping(pLadder))
	{
		pGrid->PrintErrorMessage("Two or more Ladders are Overlapping");
	}
	else
	{
		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pLadder);     // error

		bool Temp = (startPos.HCell() != -1) && (startPos.VCell() != -1) && (endPos.HCell() != -1) && (endPos.VCell() != -1);
		// if the GameObject cannot be added
		if ((!added) && (Temp) )                                    // error 
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
}