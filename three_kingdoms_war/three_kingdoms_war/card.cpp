#include "card.h"
#include "service.h"
class Player;
Card::Card(Suit _suit,string &_name,int _num)
{
	suit=_suit;
	name=_name;
	num=_num;
	if((suit==spade)||(suit==club))
		color=black;
	else if((suit==heart)||(suit==diamond))
		color=red;
	else
		color=nocolor;
}
void Card::setNum(int _num)
{
	num=_num;
}
int Card::getNum()
{
	return num;
}
void Card::setName(string &_name)
{
	name=_name;
}
string Card::getName()
{
	return name;
}
void Card::setSuit(Suit _suit)
{
	suit=_suit;
}
Suit Card::getSuit()
{
	return suit;
}
void Card::setColor(Color _color)
{
	color=_color;
}
Color Card::getColor()
{
	return color;
}
Cardtype Card::getCardtype()
{
	return card;
}
void Card::selected(Service *service,Player *from)
{
}
void Card::use(Service *service,Player *from,vector<Player *>to)
{
}
ostream & operator<<(ostream &os,Card &card)
{
	char _suit;
	switch(card.suit)
	{
	case spade:_suit=6;
		break; //ºÚÌÒASciiÂë006
	case heart:_suit=3;
		break; //ºìÌÒASCIIÂë003
	case diamond:_suit=4;
		break;
	case club:_suit=5;
		break;
	case nosuit:_suit=0;
		break;
	}
	os<<_suit<<card.num<<" "<<card.name;
	return os;
}
VirtualCard::VirtualCard(Suit _suit,string _name,int _num):Card(_suit,_name,_num)
{
	cardtype=virtualcard;
}
Cardtype VirtualCard::getCardtype()
{
	return virtualcard;
}
void VirtualCard::setCardtype(Cardtype _cardtype)
{
	cardtype=_cardtype;
}
TrickCard::TrickCard(Suit _suit,string _name,int _num):Card(_suit,_name,_num)
{
}
Cardtype TrickCard::getCardtype()
{
	return tip;
}
void TrickCard::onEffect(TrickEffectClass& tes)
{
}
EquipCard::EquipCard(Suit _suit,string &_name,int _num):Card(_suit,_name,_num)
{
}
void EquipCard::selected(Service *service,Player *from)
{
	int i=0;
	cout<<"Ê¹ÓÃ"<<*this<<"ÇëÊäÈë1£¬·ñÔòÊäÈë0¡£"<<endl;
	cin>>i;
	if(i==1)
	{
		vector<Player *> nothing;
		this->use(service,from,nothing);
	}
}
void EquipCard::use(Service *service,Player *from,vector<Player *> to)
{
	EquipCard *equipped=NULL;
	switch(this->location())
	{
	case weaponlocation:
		equipped=from->();
		break;
	case armorlocation:
		equipped=from->getArmorPtr();
		break;
	case defensivehorselocation:
		equipped=from->getDefensiveHorsePtr();
		break;
	case offensivehorselocation:
		equip
		break;
	}
}