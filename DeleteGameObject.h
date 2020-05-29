#include "Action.h"

class DeleteGameObject : public Action
{
private:

	// Always add action parameters as private data members

	CellPosition pos; // The Position where the object that needs to be deleted

public:

	DeleteGameObject(ApplicationManager* pApp); // Constructor

	virtual void ReadActionParameters(); // Reads action parameters

	virtual void Execute();

	virtual ~DeleteGameObject(); // Virtual Destructor
};