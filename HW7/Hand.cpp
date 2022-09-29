#include <iostream>

#include "Card.h"
#include "Hand.h"


Hand::Hand()
{
}


void Hand::Add(Card* pCard) {
	m_aCards.push_back(pCard);
}


void Hand::Clear() {
	m_aCards.clear();
}


const int Hand::GetValue() const {
	int nSum = 0;

	for (const Card* pCard : m_aCards) {
		Rank eValue = pCard->GetRank();
		nSum += (eValue == Rank::ACE && nSum > 10) ? 1 : Card::RankToScore(eValue);
	}

	return nSum;
}

std::vector<Card*> Hand::GetCards() const {
	return m_aCards;
}



