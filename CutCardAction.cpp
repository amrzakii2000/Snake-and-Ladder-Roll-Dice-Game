#include "CutCardAction.h"
#include "Grid.h"
#include "Card.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void CutCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter

	pOut->PrintMessage("click on the source cell");
	pos = pIn->GetCellClicked();
}

void CutCardAction::Execute()
{
		CutCardAction::ReadActionParameters();
		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		//Cell c(pos);
		//card = c.HasCard();
		//if (card)
		//{
		if (pos.IsValidCell())
		{
		pGrid->SetClipboard(pos);
		if (pGrid->GetClipboard())
		{
			pGrid->RemoveObjectFromCell(pos);
			//pOut->PrintMessage("Cut Card: Action completed sucessfully!");
		}
		//	}
			/*else
			{
				while (!card)
				{
					pOut->PrintMessage("Cut Card: Action not completed sucessfully, Please select a cell that has a card!");
					pos2 = pIn->GetCellClicked();
					pGrid->SetClipboard(card);
				}
				pGrid->RemoveObjectFromCell(pos);
				pOut->PrintMessage("Cut Card: Action completed sucessfully!");
			}*/
	}
	pOut->ClearStatusBar();
}

CutCardAction::~CutCardAction()
{
}