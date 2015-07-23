#pragma
#ifndef _SERVICE_H_
#define _SERVICE_H_
#include "allcardheader.h"
#include "deskcard.h"
#include "cardmessage.h"
class deskCard;
class Player;
class Service
{
private:
	Player *playerarray[10];
	int PlayerNum;
	deskCard *deskcard;
	bool gameover;
public:
	explicit Service();
	virtual ~Service();
	void addPlayer(Player *player);
	void setDeskCard(deskCard *deskCard);
	deskCard *getDeskCard();
	Setperiodresult setPeriod(Period *period);
	void getCardFromUnused(Player *player);
	void setCardToUsed(Card *card);
	void CheckInfo();
	int distanceTo(int seatno_from,int seatno_to);
	Player *SearchWithSeatNo(int seatno);//查看对应座位号上的角色是否还活着
	int getPlayerNum();
	int getLivePlayerNum();
	bool isGameOver();
	void setGameOver(bool go);
	vector<Player *> getAllLivePlayer(Player *from,bool withfrom);
	Message ProcessChop(chopEffectClass &chopeffectclass);
	void ProcessTrick(TrickEffectClass & tes);
	void ProcessRewardAndPunishment(Player* killer,Player* victim);
	JudgeResult getJudgeResult(Player* player);
	int AskPeach(Player* who,int need); //求桃
	bool AskNullification(TrickEffectClass& tes,bool positive);  //询问无懈
	void CheckVictory(Player* Dead);
	void FollowUpDisposal();  //所有人弃置所有牌，游戏结束
	void testStartGame();
//	Period getPeriod();

}
#endif