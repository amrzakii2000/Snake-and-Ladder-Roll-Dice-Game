#include "CardThree.h"
#include "Ladder.h"
class CardFour:public Card
{
public:
	CardFour(const CellPosition& pos);
	void Apply(Grid* pGrid, Player* pPlayer);
};