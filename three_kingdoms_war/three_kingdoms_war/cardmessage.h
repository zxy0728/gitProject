#pragma
#ifndef _CARDMESSAGE_H_
#define _CARDMESSAGE_H_
#include <vector>
using namespace std;
class Chop;
class Player;
class Card;
class VirtualCard;
class TrickCard;
enum Suit{spade,heart,diamond,club,nosuit}; //���� ���� ���� ÷�� ��ɫ
enum Sex{male,female};  //�Ա�
enum Nationality{Wei,Shu,Wu,Qun};
enum Color{red,black,nocolor};   //��ɫ �� �� ��ɫ
enum Chopprop{fire,thunder,noprop};    //�����˺� ���� �׵� ������
enum Role{lord,loyalist,renegade,rebel};    //��ɫ ���� �ҳ� �ڼ� ����
enum Period{start,judgement,take,play,discard,finish,noactive}; //�غ� ��ʼ �ж� ���� ���� ���� ���� �޻غ�
enum Place{judgeplace,equipplace,handcardplace}; //�ж��� װ���� ������
enum Location{weaponlocation,armorlocation,defensivehorselocation,offensivehorselocation};
enum Cardtype{card,basiccard,chopt,jinkt,peacht,tip,immediatelytip,delaytip,equippment,weapon,armor,defenhorse,offenhorse,nullification,virtualcard}; 
//�������� ͳ���� ������ ������ ��ʱ���� ��ʱ���� װ���� ������ ������ ������ ������ ������ ��Ч��
enum Setperiodresult{noskip,skipjudge,skiptake,skipplay,skipdiscard,lightningboom,gameend};
//�غϽ������
enum Message{nomessage,cixiongshuanggujian,jiedaosharen,chophit,chopmiss,chopnullification,injured,askpeach,recover1HP,recover2HP,recover0HP,newjudge,amazinggrace};
enum Classtype{chopEffectClassCL,trickEffectClassCL,cardUseClassCL};
//�����ǳ��ƺ�Ľ���������ж��Ƿ���Ч��ɱ����û�У������Ƿ���Ч
class MessageClass{
	virtual Classtype getClasstype()=0;
};
class chopEffectClass:public MessageClass
{
public:
	explicit chopEffectClass();
	virtual ~chopEffectClass();
	virtual Classtype getClasstype();
	Chop *chop;
    VirtualCard* virtualcard;
	//bool Jinked;
	bool Qinggang;
	bool Cixiong;
	bool Fangtian;
	bool Zhangba;
	Player* from;
	vector<Player *> to;

};
class TrickEffectClass:public MessageClass{
public:
	explicit TrickEffectClass();
	virtual ~TrickEffectClass();
	virtual Classtype getClasstype();
	TrickCard* card;
	Player* from;
	Player* to;
	Player* to1;//�赶ɱ�˵ĵڶ���Ŀ��

};
class JudgeResult{
public:
	explicit JudgeResult();
	virtual ~JudgeResult();
	Suit suit;
	int num;
};

class CardUseClass:public MessageClass{
public:
	explicit CardUseClass();
	virtual ~CardUseClass();
	virtual Classtype getClasstype();
	Card * card;
	Player* from;
	vector<Player *> to;
};
class DamageClass{
public:
	explicit DamageClass();
	virtual ~DamageClass();
	Player* from;
	Player* to;
	Card *card;
	int damage;
};
class DyingClass{
public:
	explicit DyingClass();
	virtual ~DyingClass();
	Player* who;
};
class RecoverClass{
public:
	explicit RecoverClass();
	virtual ~RecoverClass();
	int recover;
	Player* who;
};
#endif