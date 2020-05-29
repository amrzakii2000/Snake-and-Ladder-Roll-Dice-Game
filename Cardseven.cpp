#include "Cardseven.h"


Cardseven::Cardseven(const CellPosition & pos):Card(pos)
{
	cardNumber=7;
}
void Cardseven :: Apply(Grid* pGrid, Player* pPlayer)
{
	Card :: Apply( pGrid , pPlayer ) ;
	pGrid->SetCurrentPlayer(pPlayer->getplayerNum()-1);
}

Cardseven::~Cardseven()
{

}

