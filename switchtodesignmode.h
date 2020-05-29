#pragma once
#include "action.h"
class switchtodesignmode :
	public Action
{
public:
	switchtodesignmode(ApplicationManager * papp);
	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();
	~switchtodesignmode(void);
};

