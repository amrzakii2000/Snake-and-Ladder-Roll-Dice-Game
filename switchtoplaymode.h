
#include "action.h"
class Switchtoplaymode :
	public Action
{
public:
	Switchtoplaymode(ApplicationManager* papp);
	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();
	~Switchtoplaymode(void);
};
