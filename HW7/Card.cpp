#include <sstream>
#include "Card.h"

Card::Card(const Rank eRank, const Suit sSuit, const bool InFaceUp )
{
	m_Rank = eRank;
	m_Suit = sSuit;
	m_InFaceUp = InFaceUp;
}

const Rank Card::GetRank() const
{
	return m_Rank;
}
const Suit Card::GetSuit() const
{
	return m_Suit;
}

const bool Card::GetState() const 
{
	return m_InFaceUp;
}

std::string Card::SuitToString(const Suit eSuit)
{
	switch (eSuit) {
	case Suit::CLUBS:
		return "треф";
		break;

	case Suit::DIAMONDS:
		return "бубен";
		break;

	case Suit::HEARTS:
		return "червей";
		break;

	case Suit::SPADES:
		return "пик";
		break;
	}

	return "undefined";
}

std::string Card::ValueToString(const Rank eValue)
{
	switch (eValue) {
	case Rank::TWO:
		return "Двойка";
		break;

	case Rank::THREE:
		return "Тройка";
		break;

	case Rank::FOUR:
		return "Четвёрка";
		break;

	case Rank::FIVE:
		return "Пятёрка";
		break;

	case Rank::SIX:
		return "Шестёрка";
		break;

	case Rank::SEVEN:
		return "Семёрка";
		break;

	case Rank::EIGHT:
		return "Восьмёрка";
		break;

	case Rank::NINE:
		return "Девятка";
		break;

	case Rank::TEN:
		return "Десятка";
		break;

	case Rank::JACK:
		return "Валет";
		break;

	case Rank::QUEEN:
		return "Дама";
		break;

	case Rank::KING:
		return "Король";
		break;

	case Rank::ACE:
		return "Туз";
		break;
	}

	return "undefined";
}

int Card::RankToScore(const Rank eRank)
{
	switch (eRank)
	{
	case Rank::TEN:
	case Rank::JACK:
	case Rank::QUEEN:
	case Rank::KING:
		return 10;
		break;

	case Rank::ACE:
		return 11;
		break;
	}

	return static_cast<int>(eRank);
}

const std::string Card::toString() const
{
	return Card::ValueToString(m_Rank) + ' ' + Card::SuitToString(m_Suit);
}


void Card::Filp() {
	m_InFaceUp = !m_InFaceUp;
}

std::ostream& operator<< (std::ostream& out, const Card& c) {
	return out << (c.GetState() ? c.toString() : "XX");
}