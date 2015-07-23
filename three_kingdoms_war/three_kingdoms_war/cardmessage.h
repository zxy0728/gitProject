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
enum Suit{spade,heart,diamond,club,nosuit}; //黑桃 红桃 方块 梅花 无色
enum Sex{male,female};  //性别
enum Nationality{Wei,Shu,Wu,Qun};
enum Color{red,black,nocolor};   //花色 红 黑 无色
enum Chopprop{fire,thunder,noprop};    //属性伤害 火焰 雷电 无属性
enum Role{lord,loyalist,renegade,rebel};    //角色 主公 忠臣 内奸 反贼
enum Period{start,judgement,take,play,discard,finish,noactive}; //回合 开始 判定 摸牌 出牌 弃牌 结束 无回合
enum Place{judgeplace,equipplace,handcardplace}; //判定区 装备区 手牌区
enum Location{weaponlocation,armorlocation,defensivehorselocation,offensivehorselocation};
enum Cardtype{card,basiccard,chopt,jinkt,peacht,tip,immediatelytip,delaytip,equippment,weapon,armor,defenhorse,offenhorse,nullification,virtualcard}; 
//卡牌类型 统称牌 基本牌 锦囊牌 即时锦囊 延时锦囊 装备牌 武器牌 防具牌 防御马 进攻马 虚拟牌 无效牌
enum Setperiodresult{noskip,skipjudge,skiptake,skipplay,skipdiscard,lightningboom,gameend};
//回合结束结果
enum Message{nomessage,cixiongshuanggujian,jiedaosharen,chophit,chopmiss,chopnullification,injured,askpeach,recover1HP,recover2HP,recover0HP,newjudge,amazinggrace};
enum Classtype{chopEffectClassCL,trickEffectClassCL,cardUseClassCL};
//下面是出牌后的结果，比如判定是否生效，杀闪有没中，锦囊是否生效
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
	Player* to1;//借刀杀人的第二个目标

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