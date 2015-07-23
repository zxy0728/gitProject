#pragma 
#ifndef _DEFENSIVEHORSE_H_
#define _DEFENSIVEHORSE_H_
#include "card.h"
class OffensiveHorse:public EquipCard
{
public:
	explicit OffensiceHorse(Suit _suit,string & _name,int _num);
	virtual Cardtype getCardtype();
	virtual ~OffensiveHorse();
};
#endif