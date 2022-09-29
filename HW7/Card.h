#pragma once
#ifndef Card_h
#define Card_h
#include<string>
enum class Suit : int { CLUBS = 1, DIAMONDS, HEARTS, SPADES , first = CLUBS, last = SPADES};
enum class Rank : int {ACE = 1, TWO , THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, first = ACE, last = KING };


class Card {
public:
	Card() = delete;
	Card(const Rank eRank, const Suit sSuit, const bool InFaceup = true);

	const Rank GetRank() const;
	const Suit GetSuit() const;
	const bool GetState () const;

	static std::string SuitToString(const Suit eSuit);
	static std::string ValueToString(const Rank eRank);
	static int RankToScore(const Rank eRank);

	const std::string toString() const;
	

	void Filp();

protected:
	Suit m_Suit;
	Rank m_Rank;
	bool m_InFaceUp;
};

std::ostream& operator<< (std::ostream& out, const Card& c);

#endif // !Card_h

