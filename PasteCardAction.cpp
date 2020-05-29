#include "PasteCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "CopyCardAction.h"
#include "AddCardAction.h"
#include "Action.h"
#include "ApplicationManager.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

}
void PasteCardAction::ReadActionParameters()
{

}
void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card* card = new Card(pos2);
	card = pGrid->GetClipboard();

	pOut->PrintMessage("click on the destination cell");
	pos2 = pIn->GetCellClicked();
	//Cell c2(pos2);
	if (pos2.IsValidCell()&&card)
	{
		//int cn = card->GetCardNumber();
		//AddCardAction a(pManager);
		//pManager->
		//a.AddCardAction::Execute(cn, pos2);
		card->SetPosition(pos2);
		pGrid->AddObjectToCell(card, pos2);
		/*if (pGrid->AddObjectToCell(card, pos2))
		{
			pOut->PrintMessage("Paste Card: Action completed successfully!");
		}*/
		//else
		//{
		//	pOut->PrintMessage("Paste Card: Action not completed sucessfully, Please select a cell that doesn't have any object...");
		//}
		pGrid->UpdateInterface();
	}
	pOut->ClearStatusBar();
}

PasteCardAction::~PasteCardAction()
{
}
