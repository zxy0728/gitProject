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
class Nullification:public ImmediatelyTrick{//��и�ɻ����޸ģ������и�ɻ���ʱ�����ļ�ʱ���Ҳ�һ��
public:
	explicit Nullification(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
};

class ExNihilo:public ImmediatelyTrick{//��������
public:
	explicit ExNihilo(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Collateral:public ImmediatelyTrick{//�赶ɱ��
public:
	explicit Collateral(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Duel:public ImmediatelyTrick{//����
public:
	explicit Duel(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Snatch:public ImmediatelyTrick{//˳��
public:
	explicit Snatch(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class Dismantlement:public ImmediatelyTrick{//����
public:
	explicit Dismantlement(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};

class SavageAssault:public ImmediatelyTrick{//����
public:
	explicit SavageAssault(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class ArcheryAttack:public ImmediatelyTrick{//����뷢
public:
	explicit ArcheryAttack(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};

class GodSalvation:public ImmediatelyTrick{//��԰
public:
	explicit GodSalvation(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class AmazingGrace:public ImmediatelyTrick{//���
public:
	explicit AmazingGrace(Suit _suit,string& _name,int _num);
	virtual void selected(Service* service,Player* from); 
	virtual void use(Service *service,Player *from,vector<Player *>targets);
	virtual void onEffect(TrickEffectClass& tes);
};
class FireAttack:public ImmediatelyTrick  //�𹥣�������
{
public:
	explicit FireAttack(Suit _suit,string &_name,int _num);
	//virtual void selected()
};
class IronChain:public ImmediatelyTrick  //����������������
{
public:
	explicit IronChain(Suit _suit,string & _name,int _num);
	virtual ~IronChain();
};
#endif