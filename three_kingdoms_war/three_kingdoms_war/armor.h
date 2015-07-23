#pragma 
#ifndef _ARMOR_H_
#define _ARMOR_H_
#include "card.h"
class Armor:public Card
{
public:
	explicit Armor(Suit _suit,string& _name,int _num);
	virtual ~Armor();
	virtual Cardtype getCardtype();
	virtual Location location();
};
class EightDiagram:public Armor
{
public:
	explicit EightDiagram(Suit _suit,string & _name,int _num);
	virtual ~EightDiagram();
};
class RenwangShield:public Armor
{
public:
	explicit RenwangShield(Suit _suit,string & _name,int _num);
	virtual ~RenwangShield();
};
class SilverLion:public Armor
{
public:
	explicit SilverLion(Suit _suit,string &_name,int _num);
	virtual ~SilverLion();
};
class RattanArmor:public Armor
{
public:
	explicit RattanArmor(Suit _suit,string & _name,int _num);
	virtual ~RattanArmor();
};
#endif