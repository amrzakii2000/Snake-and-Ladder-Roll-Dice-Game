#include "Player.h"
#include"CardFive.h"
#include"CardSix.h"
#include"Cardseven.h"
#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	Forbidden = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======
void Player::SetForbidden(bool forbidden)
{
	Forbidden = (forbidden == true || forbidden == false) ? forbidden : false;
}
bool Player::GetForbiddden() const
{
	return Forbidden;
}
void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}
int Player::getplayerNum()
{
	return playerNum;
}
void Player::SetTurnCount(int turncount)
{
	this->turnCount = turncount > 0 ? turncount : 0;
}
void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	if (this->wallet < 0)
		this->wallet = 0;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}
CellPosition Player::GetCurrentCell() const
{
	return this->GetCell()->GetCellPosition();
}
int Player::GetjustrolledDiceNum() const
{
	return justRolledDiceNum;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(this->GetCurrentCell(), this->playerNum, cellColor);

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	if (dynamic_cast<CardFive*>(pCell->HasCard()) == NULL && dynamic_cast<CardSix*>(pCell->HasCard()) == NULL && dynamic_cast<Cardseven*>(pCell->HasCard()) == NULL)
	{
		turnCount++;
	}

	if (turnCount == 3)
	{

		string decision;

		int addwallet = diceNumber * 10;
		pGrid->GetOutput()->PrintMessage(" Special attack instead of Reacharging Wallet ? (y/n)");
		decision = pGrid->GetInput()->GetString(pGrid->GetOutput());
		if (decision == "y" && diceNumber != 0)
		{
			string attack;
			pGrid->GetOutput()->PrintMessage("Choose from your attack: Ice (i), Fire (f), Poison (p), Lightning (l). (type b to go back)");
			attack = pGrid->GetInput()->GetString(pGrid->GetOutput());

			if (attack == "b")
			{
				string decision;

				int addwallet = diceNumber * 10;
				pGrid->GetOutput()->PrintMessage(" Special attack instead of Reacharging Wallet ? (y/n)");
				decision = pGrid->GetInput()->GetString(pGrid->GetOutput());

			}
			

		}

		if (decision != "y")
		{
			pGrid->PrintErrorMessage("Now you wallet will recharge with " + to_string(addwallet) + " Coins, Click to continue");
			wallet += addwallet;
		}


	}
	justRolledDiceNum = diceNumber;

	CellPosition pos = pCell->GetCellPosition();
	pos.AddCellNum(diceNumber);
	if (diceNumber != 0 && turnCount != 3)
	{
		pGrid->UpdatePlayerCell(this, pos);

	}
	else
	{
		pGrid->PrintErrorMessage("You are not allowed to move this turn..");

	}
	if (pos.GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}

	
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (turnCount == 3)
	{
		turnCount = 0;
	}
	
}


void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
