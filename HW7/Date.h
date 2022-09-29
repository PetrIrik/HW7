#ifndef _DATE_H
#define _DATE_H

#include<ostream>
#include <iomanip>


class Date
{
private:
	int mDay;
	int mMonth;
	int mYear;

public:

	Date(int day = 1, int month = 1, int year = 1900);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
};


std::ostream& operator<<(std::ostream &out,const  Date &date);

#endif // !_DATE_H


