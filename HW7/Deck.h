#pragma once
#include "Hand.h"
#include"GenericPlayer.h"

class Deck: public Hand
{
public:
	Deck();
	virtual~Deck() = default;
	
	//создать колоду 
	void Populate();
	//рамешать карты
	void Shuffle();
	//Раздача
	void Deal(Hand &aHand);
	//раздача карт по тригиру 
	void AdditionalCards(GenericPlayer& aGenericPlayer);
	
};

