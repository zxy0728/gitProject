#pragma
#ifndef _CHOP_H_                 //杀，这里没分是打出还是使用
#define _CHOP_H_
#include "card.h"
class Chop:public Card
{
private:
	Chopprop attri;
public:
	explicit Chop(Suit _suit,string & _name,int _num);
	virtual ~Chop();
	virtual void setProp(Chopprop prop);
	virtual Chopprop getProp();
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *service,Player *from,vector<Player *> to)
};
#endif