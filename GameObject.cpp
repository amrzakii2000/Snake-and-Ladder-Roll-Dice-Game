#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

 bool  GameObject::IsOverLapping(GameObject* pNew) const
{
	 return false;
}
 void GameObject::SetPosition(CellPosition& pos)
 {
	 position = pos;
 }
GameObject::~GameObject()
{
}