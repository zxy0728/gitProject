#pragma
#ifndef _WEAPON_H_
#define _WEAPON_H_
#include "card.h"
class Weapon:public EquipCard
{
protected:
	int range;
public:
	explicit Weapon(Suit _suit,string & _name,int _num);
	virtual ~Weapon();
	virtual Cardtype getCardtype();
	virtual Location location();
	virtual void setRange(int x);
	virtual int getRange();
};
class Zhugeliannu:public Weapon
{
public:
	explicit Zhugeliannu(Suit _suit,string & _name,int _num);	
	virtual ~Zhugeliannu();
}
class Qinggang:public Weapon
{
public:
	explicit Qinggang(Suit _suit,string &_name,int _num);
	virtual ~Qinggang();
};
class Hanbing:public Weapon
{
public:
	explicit Hanbing(Suit _suit,string &_name,int _num);
	virtual ~Hanbing();
};
class Cixiong:public Weapon
{
public:
	explicit Cixiong(Suit _suit,string &_name,int _num);
	virtual ~Cixiong()
};
class Guding:public Weapon
{
public:
	explicit Guding(Suit _suit,string &_name,int _num);
	virtual ~Guding();
}
class Guanshi:public Weapon
{
public:
	explicit Guanshi(Suit _suit,string &_name,int _num);
	virtual ~Guanshi();
};
class Qinglong:public Weapon
{
public:
	explicit Qinglong(Suit _suit,string &_name,int _num);
	virtual ~Qinglong();
};
class Zhangba:public Weapon
{
public:
	explicit Zhangba(Suit _suit,string & _name,int _num);
	virtual ~Zhangba();
};
class Fangtian:public Weapon
{
public:
	explicit Fangtian(Suit _suit,string & _name,int _num);
	virtual ~Fangtian();
};
class Zhuque:public Weapon   //朱雀羽扇火杀转化先定义在这里，后面再补上杀的属性问题处理
{
public:
	explicit Zhuque(Suit _suit,string & _name,int _num);
	virtual ~Zhuque();
};
class Qilingong:public Weapon
{
public:
	explicit Qilingong(Suit _suit,string &_name,int _num);
	virtual ~Qilingong();
};
#endif