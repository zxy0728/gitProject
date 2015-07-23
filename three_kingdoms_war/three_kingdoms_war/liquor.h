#pragma                              //酒和普通牌不一样，不仅能濒死补血，也能非濒死伤害+1
#ifndef _LIQUOR_H_
#define _LIQUOR_H_
#include "card.h"
class Liquor:public Card       //暂时不使用，需要考虑使用过程
{
public:
	explicit Liquor(Suit _suit,string &_name,int _num);
	virtual ~Liquor();
};
#endif