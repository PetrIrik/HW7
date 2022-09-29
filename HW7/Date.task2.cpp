#include"Date.task2.h"


std::shared_ptr<Date>maxDate(const std::shared_ptr<Date>& date1, const std::shared_ptr<Date>& date2)
{
	if (date1.get()->GetYear() > date2.get()->GetYear())
	{
		return std::shared_ptr<Date>(date1);
	}
	else if (date1.get()->GetYear() < date2.get()->GetYear())
	{
		return std::shared_ptr<Date>(date2);
	}
	else if (date1.get()->GetMonth() > date2.get()->GetMonth())
	{
		return std::shared_ptr<Date>(date1);
	}
	else if (date1.get()->GetMonth() < date2.get()->GetMonth())
	{
		return std::shared_ptr<Date>(date2);
	}
	else if (date1.get()->GetDay() > date2.get()->GetDay())
	{
		return std::shared_ptr<Date>(date1);
	}
	else
	{
		return std::shared_ptr<Date>(date2);
	}
}

void SwapDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2)
{
	auto tmp = move(date1);
	date1 = move(date2);
	date2 = move(tmp);
}