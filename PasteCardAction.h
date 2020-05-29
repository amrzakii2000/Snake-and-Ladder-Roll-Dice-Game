#pragma once
#include "Action.h"
class PasteCardAction:public Action
{
private:
	CellPosition pos2;
	Card* card;
public:
	PasteCardAction(ApplicationManager* pApp); // A Constructor
	
	virtual void ReadActionParameters();

	virtual void Execute();
	//virtual void CopyCard();

	virtual ~PasteCardAction(); // A Virtual Destructor
};

