#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	//Done by Amr Zaki
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	//Done by Amr Zaki
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	//Done by Amr Zaki
	///TODO: Implement this function as described in the .h file
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10)
		return true;

	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

 int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	 //Done by Amr Zaki
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	///TODO: Implement this function as described in the .h file
	 int Vertical, Horizontal;
	 if (cellPosition.IsValidCell() == true)
	 {
		 Vertical = cellPosition.vCell;
		 Horizontal = cellPosition.hCell;
		 return (8 - Vertical) * 11 + (Horizontal + 1);
	 }
	 else
		 return 0;
	

}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	/// TODO: Implement this function as described in the .h file
	if (cellNum >= 1 && cellNum <= 99)
	{
		if (cellNum % 10 <= cellNum / 10)
		{
			position.SetVCell(8 - ((cellNum / 10) - 1));
			position.SetHCell(10 + (cellNum % 10) - (cellNum / 10));
		}
		else
		{
			position.SetVCell(8 - (cellNum / 10));
			position.SetHCell((cellNum % 10) - (cellNum / 10) - 1);
		}
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	/// TODO: Implement this function as described in the .h file
	int cellNum; CellPosition newposition;
	cellNum = GetCellNumFromPosition(*this) + addedNum;
	if (cellNum >= 1 && cellNum <= 99)
	{
		newposition = GetCellPositionFromNum(cellNum);
		SetVCell(newposition.vCell);
		SetHCell(newposition.hCell);
	}
	else
		return;
	// Note: this function updates the data members (vCell and hCell) of the calling object

}