#ifndef HOUSE_H
#define HOUSE_H
#include<string>
#include"GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House();

	virtual const bool IsHitting()  const override;

	void FilpFirstCard();
};
#endif // !HOUSE.H

