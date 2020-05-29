#pragma once
#include "Card.h"
#include"Player.h"


class CardFourteen : public Card
{
	static int price;
	static int fees;
	static bool flag_P_F;
	static Player* owner;
	static bool flag_owner;
	static Player* Passer;
public:
	class CardFourteen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	bool SetPrice(int p); //Ziad: Get Price, if invalid will return false, !! constant 
	bool SetFees(int f); //Ziad: Get fees, if invalid will return false  !! constant
	void SetFlagpF(bool pf);
	int GetPrice();
	int GetFees();

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardFourteen(); // A Virtual Destructor
};