

#include <iostream>
#include<ctime>
#include<locale>


#include"Date.h"
#include "Date.task2.h"
#include"Card.h"
#include"Deck.h"
#include"GenericPlayer.h"
#include"Hand.h"
#include"House.h"
#include"Player.h"

class Game
{
public:
	Game(const std::vector<std::string>& names)
	{
		for (auto& name : names)
		{
			m_Players.push_back(Player(name));
		}

		srand(static_cast<unsigned int>(time(0)));

		m_deck.Populate();
		m_deck.Shuffle();
	}

	~Game() = default;

	void Play()
	{
		std::vector<Player>::iterator pPlayer;
		//раздача
		for (size_t i = 0; i < 2; i++)
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();++pPlayer)
			{
				m_deck.Deal(*pPlayer);
			}
			m_deck.Deal(m_house);
		}

		//спрятали 1 карту дилера
		m_house.FilpFirstCard();
		// показали всех карты 
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			std::cout << *pPlayer << std::endl;
		}
		std::cout << m_house << std::endl;
		// раздает игрокам дополнительные карты

		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_deck.AdditionalCards(*pPlayer);
		}

		//показываем  первую карту дилера
		m_house.FilpFirstCard();
		std::cout << std::endl << m_house;

		//раздаем дилеру доп карту
		m_deck.AdditionalCards(m_house);

		if (m_house.IsBusted())
		{
			//все .кто остался в игре побеждают (но я не понял вот =( )
			for (pPlayer = m_Players.begin(); pPlayer !=m_Players.end();++pPlayer) 
			{
				if (!(pPlayer->IsBusted()))
				{
					pPlayer->WIN();
				}
			}
		}
		else
		{
			//сравниваем суму очков у все и у дилера

			for (pPlayer = m_Players.begin();pPlayer !=m_Players.end();++pPlayer)
			{
				if(!(pPlayer->IsBusted()))
				{
					if (pPlayer->GetValue() > m_house.GetValue())
					{
						pPlayer->WIN();
					}
					else if (pPlayer->GetValue()< m_house.GetValue())
					{
						pPlayer->LOSE();
					}
					else 
					{
						pPlayer->PUSH();
					}
				}
			}
		}
		//clear hand
		for (pPlayer = m_Players.begin();pPlayer !=m_Players.end();++pPlayer)
		{
			pPlayer->Clear();
		}
		m_house.Clear();
	}




private:
	Deck m_deck;
	House m_house;
	std::vector<Player> m_Players;
};



int main()
{
	setlocale(LC_ALL, "rus");
    time_t now = time(0);
    tm current_time;
	gmtime_s(&current_time, &now);

	auto today = std::make_unique<Date>(current_time.tm_mday, current_time.tm_mon + 1, current_time.tm_year + 1900);
	std::unique_ptr<Date> date;

	std::cout << "Сегодняшняя дата: " << std::endl;
	std::cout << "День: " << today.get()->GetDay() << std::endl;
	std::cout << "Месяц: " << today.get()->GetMonth() << std::endl;
	std::cout << "Год: " << today.get()->GetYear() << std::endl;
	std::cout << *today << std::endl;

	std::cout << "объект today: " << (static_cast<bool>(today) ? "NOT null\n" : "null\n");
	std::cout << "объект date: " << (static_cast<bool>(date) ? "NOT null\n" : "null\n");
	std::cout << "Переместим ресурс today -> date" << std::endl;
	date = move(today);
	std::cout << "объект today: " << (static_cast<bool>(today) ? "NOT null\n" : "null\n");
	std::cout << "объект date: " << (static_cast<bool>(date) ? "NOT null\n" : "null\n");

	std::cout << "Задаине 2" << std::endl;
	auto date1 = std::make_shared<Date>(29, 9, 2022);
	auto date2 = std::make_shared<Date>(30, 9, 2022);
	std::cout << "date1 = " << *date1 << std::endl;
	std::cout << "date2 = " << *date2 << std::endl;

	auto dates = maxDate(date1, date2);
	std::cout <<"date = " << *dates << std::endl;
	std::cout << "date1: " << *date1 << std::endl;
	std::cout << "date2: " << *date2 << std::endl << std::endl;

	std::cout << "Меняем местами date1 и date2: " << std::endl;
	SwapDate(date1, date2);
	std::cout << "date1: " << *date1 << std::endl;
	std::cout << "date2: " << *date2 << std::endl << std::endl;

	std::cout << "Проверяем что dateMax остался живым " << std::endl;
	std::cout << "dateMax: " << *dates << std::endl;


	std::cout << " Сыгрем в Black Jack!" << std::endl;
	int numPlayer{ 0 };
	while (numPlayer<1||numPlayer>7)
	{
		std::cout << "Сколько играков (1-7) ";
		std::cin >> numPlayer;
	}
	std::vector<std::string> names;
	names.reserve(numPlayer);
	std::string name;
	for (int i = 0; i < numPlayer; ++i)
	{
		std::cout << "Введите ник " << i + 1<< ' ';
		std::cin >> name;
		names.push_back(name);
	}
	std::cout << std::endl;

	Game aGame(names);
	char again = 'y';
	while (again != 'n'&& again !='N')
	{
		aGame.Play();
		std::cout << " Хотите сыграть снова? (Y/N) ";
		std::cin >> again;
	}
}
