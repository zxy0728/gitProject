#pragma
#ifndef _CHOP_H_                 //ɱ������û���Ǵ������ʹ��
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