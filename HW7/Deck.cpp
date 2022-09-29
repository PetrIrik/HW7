#include<iostream>
#include"Deck.h"
#include <algorithm>
#include <random>


Deck::Deck()
{
	m_aCards.reserve(52);
	Populate();
};

void Deck::Populate()
{
	Clear();
	
	for (int s = static_cast<int>(Suit::CLUBS); s <= static_cast<int>(Suit::SPADES); ++s)
	{
		for (int r = static_cast<int>(Rank::ACE); r <= static_cast<int>(Rank::KING); ++r)
		{
			Add(new Card(static_cast<const Rank>(r),
				static_cast<const Suit >(s)));
		}
	}
}



void Deck::Shuffle()
{
	random_shuffle(m_aCards.begin(), m_aCards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_aCards.empty())
	{
		aHand.Add(m_aCards.back());
		m_aCards.pop_back();
	}
	else
	{
		std::cout << "Кончились карты. Не в состоянии раздать.";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << std::endl;
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;
		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	}

};

