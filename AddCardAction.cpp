#include "AddCardAction.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"Cardseven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"Cardtwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"
//Corner Case of Card Five and Card Six
AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
							// Initializes the pManager pointer of Action with the passed pointer

}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter Card Number : ");
	cardNumber = pIn->GetInteger(pOut);

	if (cardNumber < 1 || cardNumber>14)
	{
		pGrid->PrintErrorMessage("Invalid Card Number");
		return;

	}
	else {
		pOut->PrintMessage("Click on the cell you desire : ");
		cardPosition = pIn->GetCellClicked();

		if (!cardPosition.IsValidCell())
		{
			pGrid->PrintErrorMessage("Invalid cell Position");
			return;
		}
	}
	pOut->ClearStatusBar();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	// 2- Read the "cardNumber" parameter and set its data member

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
}

void AddCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	ReadActionParameters();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new Cardseven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition, pGrid);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new Cardtwelve(cardPosition);
		break;
	case 13:
		pCard = new CardThirteen(cardPosition);
		break;
	case 14:
		pCard = new CardFourteen(cardPosition);
		break;
		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard && cardPosition.IsValidCell())
	{
		pCard->ReadCardParameters(pGrid);

		if (!pGrid->AddObjectToCell(pCard))
		{
			pGrid->PrintErrorMessage("The cell already has another gameobject");
		}

	}	// A- We get a pointer to the Grid from the ApplicationManager

			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

			// C- Add the card object to the GameObject of its Cell:

			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

}

// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction


