#include "DeleteGameObject.h"
// #include "DeleteAction.h"
#include "Output.h"
#include "Input.h"
#include"Grid.h"
#include "ApplicationManager.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteGameObject::~DeleteGameObject()
{
}

void DeleteGameObject::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces from the ApplicationManger

	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();     // Error 

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Delete game object: Click on its Cell ...");

	// Read the cell position of the game object
	pos = pIn->GetCellClicked();

	// The only action parameter of DeleteGameObject is the the cell position
	// Action parameters are the inputs you need to take from the user after choosing the icon of the action
	// to be able to perform the action

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void DeleteGameObject::Execute()
{
	// The first line of any Action Execution is to read its parameter first and hence initializes its data members
	ReadActionParameters();

	// Delete the game object with the parameters read from the user
	//Delete * D1= new Delete; we cant do this 

	

	 Grid* pGrid = pManager->GetGrid();  
	 pGrid->RemoveObjectFromCell(pos);
}