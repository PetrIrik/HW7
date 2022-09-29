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
		return "����";
		break;

	case Suit::DIAMONDS:
		return "�����";
		break;

	case Suit::HEARTS:
		return "������";
		break;

	case Suit::SPADES:
		return "���";
		break;
	}

	return "undefined";
}

std::string Card::ValueToString(const Rank eValue)
{
	switch (eValue) {
	case Rank::TWO:
		return "������";
		break;

	case Rank::THREE:
		return "������";
		break;

	case Rank::FOUR:
		return "�������";
		break;

	case Rank::FIVE:
		return "������";
		break;

	case Rank::SIX:
		return "�������";
		break;

	case Rank::SEVEN:
		return "������";
		break;

	case Rank::EIGHT:
		return "��������";
		break;

	case Rank::NINE:
		return "�������";
		break;

	case Rank::TEN:
		return "�������";
		break;

	case Rank::JACK:
		return "�����";
		break;

	case Rank::QUEEN:
		return "����";
		break;

	case Rank::KING:
		return "������";
		break;

	case Rank::ACE:
		return "���";
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