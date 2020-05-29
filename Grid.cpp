#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include"Snake.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

bool Grid::AddObjectToCell(GameObject* pNewObject, CellPosition pos2)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	//CellPosition pos = pNewObject->GetPosition();
	if (pos2.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos2.VCell()][pos2.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos2.VCell()][pos2.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

bool  Grid::IsOverLapping(GameObject* pNew) const
{
	CellPosition NewObjectPosition = pNew->GetPosition();

	if (dynamic_cast<Ladder*>(pNew))
	{

		for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
			{
				Ladder* CurrLadder = CellList[i][j]->HasLadder();
				if (CurrLadder && CurrLadder->GetPosition().HCell() == NewObjectPosition.HCell())
				{
					if (CurrLadder->IsOverLapping(pNew))
					{
						return true;
					}
				}
			}

		}
	}
	else
	{
		for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
			{
				Snake* CurrSnake = CellList[i][j]->HasSnake();
				if (CurrSnake && CurrSnake->GetPosition().HCell() == NewObjectPosition.HCell())
				{
					if (CurrSnake->IsOverLapping(pNew))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Grid::EditableCard(Card*& pCard, CellPosition& cardPosition)
{
	if (pCard == NULL)
	{
		pCard = CellList[cardPosition.VCell()][cardPosition.HCell()]->HasCard();

	}
}

void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
	//Apply the effect of the gameobject int the updated cell on the player ( if there is)
	GameObject* UpdatedCellObject = player->GetCell()->GetGameObject();
	if (UpdatedCellObject)
	{
		UpdatedCellObject->Apply(this, player);
	}
}



// ========= Setters and Getters Functions =========

Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}
void Grid::SetCurrentPlayer(int Playernum)
{
	currPlayerNumber = Playernum;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}
void Grid::SetClipboard(CellPosition pos) // to be used in Copy
{
	Card* pCard;
	pCard = CellList[pos.VCell()][pos.HCell()]->HasCard();
	Clipboard = pCard;
}
Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========

Player* Grid::GetPlayerfromNum(int playerNum)
{
	if (playerNum<0 || playerNum>MaxPlayerCount)
	{
		return NULL;
	}
	return PlayerList[playerNum];
}
Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			if (CellList[i][j]->HasLadder())
			{
				return CellList[i][j]->HasLadder();
			}
			///TODO: Check if CellList[i][j] has a ladder, if yes return it


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the snake in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			if (CellList[i][j]->HasSnake())
			{
				return CellList[i][j]->HasSnake();
			}
			///TODO: Check if CellList[i][j] has a snake, if yes return it


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
// ========= User Interface Functions =========





void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::ResetGame()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		UpdateInterface();
		PlayerList[i]->SetWallet(100);
		PlayerList[i]->SetTurnCount(0);
		UpdatePlayerCell(PlayerList[i], CellPosition::GetCellPositionFromNum(1));

	}
	currPlayerNumber = 0;
}
void Grid::DataToSave(Ladder** l, Snake** s, Card** c, int& nl, int& ns, int& nc)
{
	nl = 0;
	nc = 0;
	ns = 0;
	for (int j = 0; j <= NumVerticalCells; j++)
	{
		for (int i = 0; i <= NumHorizontalCells; i++)
		{
			if (CellList[j][i]->HasSnake())
			{
				ns++;
				continue;
			}
			if (CellList[j][i]->HasLadder())
			{
				nl++;
				continue;
			}
			if (CellList[j][i]->HasCard())
			{
				nc++;
				continue;
			}
		}
	}
	l = new Ladder* [nl];
	s = new Snake* [ns];
	c = new Card* [nc];
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	for (int j = 0; j <= NumVerticalCells; j++)
		for (int i = 0; i <= NumHorizontalCells; i++)
		{
			if (CellList[j][i]->HasSnake())
			{
				s[c1] = (CellList[j][i]->HasSnake());
				c1++;
				continue;
			}
			if (CellList[j][i]->HasLadder())
			{
				l[c2] = (CellList[j][i]->HasLadder());
				c2++;
				continue;
			}
			if (CellList[j][i]->HasCard())
			{
				c[c3] = (CellList[j][i]->HasCard());
				c3++;
				continue;
			}
		}
}
Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}