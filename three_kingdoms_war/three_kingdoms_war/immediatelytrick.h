#pragma
#ifndef _IMMEDIATELYTRICK_H_
#define _IMMEDIATELYTRICK_H_
#include "card.h"
class ImmediatelyTrick:public TrickCard
{
public:
	explicit ImmediatelyTrick(Suit _suit,string &_name,int _num);
	virtual Cardtype getCardtype();
};
class Nullification:public ImmediatelyTrick{//无懈可击，修改，打出无懈可击的时机与别的即时锦囊不一样
public:
	explicit Nullification(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
};

class ExNihilo:public ImmediatelyTrick{//无中生有
public:
	explicit ExNihilo(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Collateral:public ImmediatelyTrick{//借刀杀人
public:
	explicit Collateral(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Duel:public ImmediatelyTrick{//决斗
public:
	explicit Duel(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Snatch:public ImmediatelyTrick{//顺手
public:
	explicit Snatch(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Dismantlement:public ImmediatelyTrick{//过拆
public:
	explicit Dismantlement(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};

class SavageAssault:public ImmediatelyTrick{//南蛮
public:
	explicit SavageAssault(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class ArcheryAttack:public ImmediatelyTrick{//万箭齐发
public:
	explicit ArcheryAttack(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};

class GodSalvation:public ImmediatelyTrick{//桃园
public:
	explicit GodSalvation(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class AmazingGrace:public ImmediatelyTrick{//五谷
public:
	explicit AmazingGrace(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class FireAttack:public ImmediatelyTrick  //火攻，完善中
{
public:
	explicit FireAttack(Suit _suit,string &_name,int _num);
	//virtual void selected()
};
class IronChain:public ImmediatelyTrick  //铁锁连环，完善中
{
public:
	explicit IronChain(Suit _suit,string & _name,int _num);
	virtual ~IronChain();
};
#endif