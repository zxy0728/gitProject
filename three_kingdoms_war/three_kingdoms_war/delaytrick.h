#pragma
#ifndef _DELAYTRICK_H_
#define _DELAYTRICK_H_
#include "card.h"
class DelayTrick:public TrickCard
{
public:
	explicit DelayTrick(Suit _suit,string &_name,int _num);
	virtual ~DelayTrick();
	virtual Cardtype getCardtype();
};
class Indulgence:public DelayTrick //¿÷≤ªÀº Ò
{
public:
	explicit Indulgence(Suit _suit,string & _name,int _num);
	virtual ~Indulgence();
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *service,Player *from,vector<Player *> to);
};
class Lightening:public DelayTrick //…¡µÁ
{
public:
	explicit Lightening(Suit _suit,string &_name,int _num);
	virtual ~Lightening();
	virtual void selected(Service *service.Player *from);
	virtual void use(Service *service,Player * from,vector<Player *> to);
	virtual void onEffect(TrickEffectClass &tes);
};
class CropShortage:public DelayTrick //±¯¡∏¥Á∂œ
{
public:
	explicit CropShortage(Suit _suit,string & _name,int _num);
	virtual ~CropShortage();
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *servic,Player *from,vector<Player *> to);
}
#endif