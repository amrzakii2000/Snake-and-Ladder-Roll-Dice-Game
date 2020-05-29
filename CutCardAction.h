#pragma once
#include "Action.h"
class CutCardAction :
	public Action
{
private:
	CellPosition pos, pos2;
	//Card* card;
public:
	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();
	//virtual void CopyCard();

	virtual ~CutCardAction(); // A Virtual Destructor
};

