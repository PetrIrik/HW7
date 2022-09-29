#include"House.h"

House::House() :GenericPlayer("Диллер")
{
}

const bool House::IsHitting() const
{
	return GetValue() >= 16;
}

void House::FilpFirstCard()
{
	if (m_aCards.size()>0)
	{
		m_aCards[0]->Filp();
	}
}