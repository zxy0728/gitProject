#pragma 
#ifndef _DEFENSIVEHORSE_H_
#define _DEFENSIVEHORSE_H_
#include "card.h"
class DefensiveHorse:public EquipCard
{
public:
	explicit DefensiveHorse(Suit _suit,string & _name,int _num);
	virtual Cardtype getCardtype();
	virtual ~DefensiveHorse();
};

#endif