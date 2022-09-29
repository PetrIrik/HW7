#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include"GenericPlayer.h"

class Player : public GenericPlayer
{
public: 
	Player () = default;
	Player(const std::string& name);

	virtual const bool IsHitting() const override;
	void WIN() const;
	void LOSE() const;
	void PUSH() const;
};

#endif // !PLAYER.h

