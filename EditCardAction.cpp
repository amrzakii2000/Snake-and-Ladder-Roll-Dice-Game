#include "EditCardAction.h"
#include"Grid.h"
#include"Card.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"Cardtwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"
EditCardAction::EditCardAction(ApplicationManager* pApp):Action(pApp)
{
	pCard = NULL;
}

 void EditCardAction::ReadActionParameters() 
{
	 Grid* pGrid = pManager->GetGrid();
	 Output* pOut = pGrid->GetOutput();
	 Input* pIn = pGrid->GetInput();
	 pOut->PrintMessage("Edit Card: Click on source to Edit... ");
	 cardPosition = pIn->GetCellClicked();

	 if (!cardPosition.IsValidCell())
	 {
		 pGrid->PrintErrorMessage("Invalid Cell Position");

	 }
	 pGrid->EditableCard(pCard, cardPosition);
	 
	 if (pCard == NULL)
	 {
		 pGrid->PrintErrorMessage("The Source has no Card to edit");
	 }
	 else
	 {
		 CardNumber = pCard->GetCardNumber();
		 if (CardNumber >= 3 && CardNumber <= 8)
		 {
			 pGrid->PrintErrorMessage("Error ! Uneditable Card...");
			 pCard = NULL;
		 }
	 }
} 
void EditCardAction::Execute() {
	Grid* pGrid = pManager->GetGrid();

	ReadActionParameters();
	if (pCard)
	{
		if (CardNumber == 10)
		{

			CardTen* Cardedit = dynamic_cast<CardTen*>(pCard);
			Cardedit->SetFlagpF(0);
			Cardedit->ReadCardParameters(pGrid);
		}
		else if (CardNumber == 11)
		{
			CardEleven* Cardedit = dynamic_cast<CardEleven*>(pCard);
			Cardedit->SetFlagpF(0);
			Cardedit->ReadCardParameters(pGrid);
		}
		else if (CardNumber == 12) {
			Cardtwelve* Cardedit = dynamic_cast<Cardtwelve*>(pCard);
			Cardedit->SetFlagpF(0);
			Cardedit->ReadCardParameters(pGrid);
		}
		else if (CardNumber == 13) {
			CardThirteen* Cardedit = dynamic_cast<CardThirteen*>(pCard);
			Cardedit->SetFlagpF(0);
			Cardedit->ReadCardParameters(pGrid);
		}
		else if (CardNumber == 14)
		{
			CardFourteen* Cardedit = dynamic_cast<CardFourteen*>(pCard);
			Cardedit->SetFlagpF(0);
			Cardedit->ReadCardParameters(pGrid);
		}
		else
		{
			pCard->ReadCardParameters(pGrid);
		}
	}

}

EditCardAction::~EditCardAction(){
 
 }