#include "switchtoplaymode.h"
#include"Grid.h"

Switchtoplaymode::Switchtoplaymode(ApplicationManager* papp): Action(papp)
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->GetOutput()->CreatePlayModeToolBar();
}

void Switchtoplaymode::ReadActionParameters()
{

}

void Switchtoplaymode::Execute()
{

}
Switchtoplaymode::~Switchtoplaymode(void)
{
}
