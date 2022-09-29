#ifndef HAND_H
#define HAND_H

#include <vector>
#include<string>
#include "Card.h"

class Hand {
public:
	Hand();

	void Add(Card* pCard);
	void Clear();
	const int GetValue()const;
	std::vector<Card*> GetCards() const;

protected:
	std::vector<Card*> m_aCards;
};


#endif // __HAND_H