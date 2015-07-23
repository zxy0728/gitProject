#pragma
#ifndef _PEACH_H_
#define _PEACH_H_
#include "card.h"
class Peach:public Card
{
public:
	explicit Peach(Suit _suit,string &_name,int _num);
	virtual ~Peach();
	virtual Cardtype getCardtype();
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *service,Player *from,vector<Player *> to);
};
#endif