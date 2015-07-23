#pragma
#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include "cardmessage.h"
#include <iostream>
#include <vector>
using namespace std;
class Service;
class Player;
class Card
{
private:
	Color color;      //颜色
	Suit suit;       //花色
	string name;     //牌名
	int num;         //点数
public:
	explicit Card(Suit _suit,string &_name,int _num);
	virtual ~Card();
	virtual void setNum(int _num);
	virtual int getNum();
	virtual string getName();
	virtual void setName(string &_name);
	virtual void setSuit(Suit _suit);
	virtual Suit getSuit();
	virtual void setColor(Color _color);
	virtual Color getColor();
	friend ostream & operator<<(ostream &os,Card &card);
	virtual Cardtype getCardtype();
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *service,Player *from,vector<Player *>to);
};
class VirtualCard:public Card     //丈八蛇矛以及于吉设置的端口，丈八两张模拟一张杀，于吉蛊惑一张牌
{
public:
	explicit VirtualCard(Suit _suit,string _name,int _num);
	virtual ~VirtualCard();
	vector<Card*> subcard;
	virtual Cardtype getCardtype();
	virtual void setCardtype(Cardtype _cardtype);     //本身牌的类型已定，但是于吉蛊惑的时候需要重新为牌设置类型
	Cardtype cardtype;
	string Info;         //备注性质
};
class TrickCard:public Card       //锦囊牌
{
public:
	explicit TrickCard(Suit _suit,string _name,int _num);
	virtual ~TrickCard();
	virtual Cardtype getCardtype();
	virtual void onEffect(TrickEffectClass &tes);
};
class EquipCard:public Card
{
public:
	enum Location{
		WeaponLocation,
		ArmorLocation,
        DefensiveHorseLocation,
        OffensiveHorseLocation,
	};
	explicit EquipCard(Suit _suit,string &_name,int _num);
	virtual void selected(Service *service,Player *from);
	virtual void use(Service *service,Player *from,vector<Player *> to);
	virtual Location location()=0 ;  //装备牌在哪个位置
	virtual bool EquipSkill()=0;     //装备技能，暂时没有分锁定技非锁定技
};
#endif