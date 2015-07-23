#pragma
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "deskcard.h"
#include "cardmessage.h"
#include "service.h"
class Player
{
private:
	string name;
	int hp;
	int hp_max;
	Sex sex;
	Nationality nationality;
	Role role;
	vector<Card *> handCard;           //手牌
	vector<DelayTrick *> JudgeCard;    //判定区的牌
	vector<EquipCard *> EquipmentCard;   //装备牌
	Period period;
	int SeatNo;
	bool ChopUsed;
	bool alive;
	deskCard *deskcard;
	Service *service;
public:
	explicit Player(deskCard * _deskcard,Service * _service,
		string _name,int _hp_max,Sex _sex,
		Nationality _nationality,int _SeatNo,Role _role);
	virtual ~Player();
	virtual void getCard();
	virtual void setCardToPlace(Card *card,Place Where);
	virtual void disCard();
	virtual void disCard(Place Where,int no);
	virtual void disCard(Place Where,Card *card);
	virtual void removeCard(Place Where,Card *card);
	virtual Card *returnCard(Place Where,int no);
	virtual void moveCardToProcess(Card* card);
	virtual bool askLeadCard(Cardtype cardtype);  //响应杀闪无懈，决斗，南蛮，万剑
	virtual Message replyMessage(Message message,Player* player,Card* card);
	virtual bool replyMessage(Message message);
	virtual bool replyAskNullification(TrickEffectClass& tes,bool positive);
	virtual void throwAllCard(bool withJudgePoker);
	virtual Setperiodresult setPhase(Period period);
	void CheckHandCard();
	void CheckEquipCard();
	void CheckJudgeCard();
	void CheckAllInfo();
	void CheckAllInfoMyself();
	Service* getService();
	string getName();
	int getSeatNo();
	int getHandCardNum();
	int getJudgeCardNum();
	int getEquipmentCardNum();
	int getHP();
	void setHP(int _hp);
	void setChopUsed();
	bool getChopUsed();
	int getHPMax();
	Sex getSex();
	void setRole(Role _role);
	Role getRole();
	bool isLive();
	virtual void getDamage(Player* from,Card* Card,int damage);
	bool hasWeapon();
	string getWeaponName();
	int getWeaponRange();
	EquipCard* getWeaponPtr();
	bool hasArmor();
	string getArmorName();
	EquipCard* getArmorPtr();
	bool hasDefensiveHorse();
	EquipCard* getDefensiveHorsePtr();
	bool hasOffensiveHorse();
	EquipCard* getOffensiveHorsePtr();
	bool hasNullification();
	bool hasCard(Place Where,string name);
};
#endif