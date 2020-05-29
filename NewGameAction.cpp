#include "NewGameAction.h"
#include"Grid.h"


NewGameAction::NewGameAction(ApplicationManager* pApp):Action(pApp)
{

}

void  NewGameAction::ReadActionParameters()
{

 }

void  NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Are you sure that you want to start a new game ?");
	string decision = pIn->GetString(pOut);
	if (decision == "y" || decision == "Y")
	{
		
		pGrid->ResetGame();
	}
}


 NewGameAction::~NewGameAction()
 {

 }