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
	Color color;      //��ɫ
	Suit suit;       //��ɫ
	string name;     //����
	int num;         //����
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
class VirtualCard:public Card     //�ɰ���ì�Լ��ڼ����õĶ˿ڣ��ɰ�����ģ��һ��ɱ���ڼ��ƻ�һ����
{
public:
	explicit VirtualCard(Suit _suit,string _name,int _num);
	virtual ~VirtualCard();
	vector<Card*> subcard;
	virtual Cardtype getCardtype();
	virtual void setCardtype(Cardtype _cardtype);     //�����Ƶ������Ѷ��������ڼ��ƻ��ʱ����Ҫ����Ϊ����������
	Cardtype cardtype;
	string Info;         //��ע����
};
class TrickCard:public Card       //������
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
	virtual Location location()=0 ;  //װ�������ĸ�λ��
	virtual bool EquipSkill()=0;     //װ�����ܣ���ʱû�з���������������
};
#endif