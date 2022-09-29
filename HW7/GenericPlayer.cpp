#pragma once

#include <iostream>

#include "Hand.h"
#include "GenericPlayer.h"


GenericPlayer::GenericPlayer(const std::string& name) : m_name(name), Hand() {
}


const std::string& GenericPlayer::GetName() const {
	return m_name;
}


const bool GenericPlayer::IsBusted() const {
	return GetValue() > 21 ? true : false;
}


void GenericPlayer::Bust() const {
	std::cout << std::endl << m_name << " перебрал! " << std::endl;
}


std::ostream& operator<< (std::ostream& out, const GenericPlayer& p) {
	std::vector<Card*> aCards = p.GetCards();

	out << p.GetName() << ":\n";

	if (!aCards.empty()) {
		for (const Card* pCard : aCards) {
			out << "* " << *pCard << std::endl;
		}
	}
	else {
		out << "Рука пустая" << std::endl;
	}

	out << "\nСумма очков: " << +p.GetValue() << std::endl;

	return out;
}