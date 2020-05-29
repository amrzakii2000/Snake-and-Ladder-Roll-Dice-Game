#include "CardEleven.h"
// #include"Grid.h"
// #include"Action.h"
#include "ApplicationManager.h"
int  CardEleven::price = 0;
int  CardEleven::fees = 0;
bool CardEleven::flag_P_F = false;
bool CardEleven::flag_owner = false;
Player* CardEleven::owner = NULL;
Player* CardEleven::Passer = NULL;

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (1 here)
}

CardEleven::~CardEleven(void)
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	// Grid* pGrid = pManager->GetGrid();      //error ***************** pManager
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (!flag_P_F)  // if the price and the fees werenot set before set them 
	{
		pOut->PrintMessage("New Card 11: Enter its card price ...");
		bool z1, z2;

		int p = pIn->GetInteger(pOut); //error *****************
		z1 = SetPrice(p);
		if (!z1) // price is in valid
		{
			pGrid->PrintErrorMessage("Invalid Price ! Click to continue ...");
			while (!z1)
			{
				// pGrid->PrintErrorMessage("Invalid input .. Click to continue ");
				pOut->PrintMessage("Enter again the card price ... ");
				p = pIn->GetInteger(pOut); //error *****************
				z1 = SetPrice(p);
			}
		}
		pOut->PrintMessage("New Card 10: Enter its card passing fees ...");
		// Read the cell position of the game object
		int f = pIn->GetInteger(pOut);
		z2 = SetFees(f);
		if (!z2) // fees is invalid
		{
			pGrid->PrintErrorMessage("Invalid Fees ! Click to continue ...");
			while (!z2)
			{
				pOut->PrintMessage("Enter the card fees again ... ");
				p = pIn->GetInteger(pOut); //error *****************
				z2 = SetFees(p);
			}
		}
		flag_P_F = true;
	}

	// Do I need to read the card position here

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

bool CardEleven::SetPrice(int p)
{
	if (p > 0)
	{
		price = p;
		return true;
	}
	else
	{
		price = -1;
		return false;
	}
}
void CardEleven::SetFlagpF(bool pf)
{
	flag_P_F = pf;
}
bool CardEleven::SetFees(int f)
{
	if (f > 0)
	{
		fees = f;
		return true;
	}
	else
	{
		fees = -1;
		return false;
	}
}

int CardEleven::GetPrice()
{
	return price;
}

int CardEleven::GetFees()
{
	return fees;
}


void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	// Grid* pGrid = pManager->GetGrid();      //error ***************** pManager
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	// 2- function of card 11

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	//
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	if (price == -1 || fees == -1) // invalid ... Apply nothing 
	{

	}
	else // normal implementaion of Apply 
	{
		if (!flag_owner) // No owner yet
		{
			pOut->PrintMessage("Do you want to buy card " + to_string(cardNumber) + " (Y/N) ");
			string z = pIn->GetString(pOut);
			//pOut->PrintMessage("Click to continue ... ");
			//int x, y;
			//pIn->GetPointClicked(x, y);
			//pOut->ClearStatusBar();
			while (z != "Y" && z != "N")
			{
				pGrid->PrintErrorMessage("Invalid input .. Click to continue ");
				pOut->PrintMessage("Do you want to buy card " + to_string(cardNumber) + " (Y/N) ");
				z = pIn->GetString(pOut);
			}
			if (z == "Y")
			{
				if ((pPlayer->GetWallet() - price) < 0)
				{
					pGrid->PrintErrorMessage("You don't have enough money to buy the card .. Click to continue ");
				}
				else
				{
					owner = pPlayer; // make him the owner
					pGrid->PrintErrorMessage("You have: " + to_string(owner->GetWallet()) + " and the price is: " + to_string(price) + " Click to continue ...");
					int wallet = owner->GetWallet();
					owner->SetWallet(wallet - price);
					flag_owner = true;
					pGrid->PrintErrorMessage("Congratulations ^^ .. you are the owner of cards " + to_string(cardNumber) + " .. Click to continue ");

				}
			}
			else  // z == "N"
			{
				pGrid->PrintErrorMessage("Your answer is NO .. Click to continue ");
			}
			// pOut->ClearStatusBar();
		}
		else // there is an owner
		{
			Passer = pPlayer;
			if (Passer == owner) // if he is the owner .. do nothing 
			{
				pGrid->PrintErrorMessage("Welcome mr.owner ^^ .. Click to continue ");
			}
			else
			{
				int wallet = Passer->GetWallet();
				if ((Passer->GetWallet() - fees) < 0) // doesn't have enough money
				{
					//task: prevent him from moving ... change roll number into coins .. add to his wallet
					if ((Passer->GetWallet() - fees) < 0)
					{
						Passer->SetTurnCount(2); // Next roll add to your wallet 
						pGrid->PrintErrorMessage("You have " + to_string(Passer->GetWallet()) + " and fees are: " + to_string(fees) + " Click to continue ...");
					}
				}
				else if ((wallet - fees) > 0) // have enough money
				{
					Passer->SetWallet(wallet - fees);
					owner->SetWallet(owner->GetWallet() + fees);
					pGrid->PrintErrorMessage("Your wallet has become " + to_string(Passer->GetWallet()) + ". Click to continue ...");
				}
			}
		}
	}
}