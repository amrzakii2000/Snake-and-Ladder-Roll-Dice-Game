#pragma once
#include"Action.h"
#include"Card.h"

class EditCardAction:public Action
{
	int CardNumber;
	CellPosition cardPosition;
	Card* pCard;
public:
	EditCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~EditCardAction();
};

