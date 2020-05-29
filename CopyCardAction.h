#pragma once
#include "Action.h"
class CopyCardAction :
	public Action
{
private:
	CellPosition pos,pos2;
	Card* card;
public:
	CopyCardAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();
	//virtual void CopyCard();

	virtual ~CopyCardAction(); // A Virtual Destructor
};

