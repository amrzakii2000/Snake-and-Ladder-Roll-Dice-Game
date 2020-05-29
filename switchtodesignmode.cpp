#include "switchtodesignmode.h"
#include "Grid.h"

switchtodesignmode::switchtodesignmode(ApplicationManager * papp):Action(papp)
{
	
	Grid*pgrid = pManager->GetGrid() ;
	pgrid->GetOutput()->CreateDesignModeToolBar();
	pgrid->ResetGame();
}
void switchtodesignmode::ReadActionParameters()
{

}

void switchtodesignmode::Execute()
{

}
switchtodesignmode::~switchtodesignmode(void)
{
}
