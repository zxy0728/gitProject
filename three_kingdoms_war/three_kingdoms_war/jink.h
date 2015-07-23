#pragma
#ifndef _JINK_H_
#define _JINK_H_
#include "card.h"
class Jink:public Card
{
	explicit Jink(Suit _suit,string &_name,int _num);
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *service,Player *from,vector<Player *> to);
};
#endif