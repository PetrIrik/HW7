#include <iostream>
#include "Player.h"
#include <conio.h>

Player::Player(const std::string& name) : GenericPlayer(name)
{
}

const bool Player::IsHitting() const
{
	int cChoice;
	std::cout << "Нужна карта?(y/n)" << std::endl;
	do
	{
		cChoice = _getch();
	} while (cChoice !='n'&&cChoice!='y');

	return cChoice == 'y';
}

void Player::WIN() const
{
	std::cout << m_name << "выграл!" << std::endl;
}

void Player::LOSE() const
{
	std::cout << m_name << "проиграл!" << std::endl;
}

void Player::PUSH() const
{
	std::cout << m_name << "Ничья!" << std::endl;
}