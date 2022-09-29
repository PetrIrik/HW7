#include "Date.h"

Date::Date(int day, int month, int year)
	: mDay(day), mMonth(month), mYear(year)
{
}

int Date::GetDay() const { return mDay; }

int Date::GetMonth() const { return mMonth; }

int Date::GetYear() const { return mYear; }

 std::ostream& operator<<(std::ostream& out, const Date& date)
{
	 out << std::setw(2) << std::setfill('0') << date.GetDay() << '.'
		 << std::setw(2) << std::setfill('0') << date.GetMonth() << '.'
		 << std::setw(2) << std::setfill('0') << date.GetYear() << '.' << std::endl;
	 
	 return out;
}

