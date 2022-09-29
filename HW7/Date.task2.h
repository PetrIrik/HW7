#pragma once
#include<memory>
#include"Date.h"

std::shared_ptr<Date>lastDate(const std::shared_ptr<Date>& date1, const std::shared_ptr<Date>& date2);

void SwapDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2);
