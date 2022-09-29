#ifndef __GENERIC_PLAYER_HP
#define __GENERIC_PLAYER_HP

#include <string>

#include "Hand.h"


class GenericPlayer : public Hand {
public:
	GenericPlayer() = delete;
	GenericPlayer(const std::string& name);

	const std::string& GetName() const;

	const bool IsBusted() const;
	void Bust() const;

	virtual const bool IsHitting() const = 0;

protected:
	std::string m_name;
};

std::ostream& operator<< (std::ostream& out, const GenericPlayer& p);

#endif // __GENERIC_PLAYER_HPP_INCLUDED__
