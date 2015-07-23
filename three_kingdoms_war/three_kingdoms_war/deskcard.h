#pragma
#ifndef _DESKCARD_H_
#define _DESTCARD_H_
#include <vector>
using namespace std;
class Card;
class deskCard
{
private:
	vector<Card *> Unused,Used,Process,OnGerneral;
public:
	explicit deskCard();
	virtual ~deskCard();
	Card *getTop();
	int setCardToTop(Card * card);//观星等技能可用
	int setCardToUnder(Card *card);
	int setCardToUsed(Card *card);   //把牌扔入弃牌堆
	int setCardToProcess(Card *card); //游戏过程中所有在场上的牌
	vector<Card *> getAllProcessCard();
	Card *getTopProcessCard();
	void moveProcessToUsed();
	void eraseAllProcessCard();
	int CardNum();
	void testPrintDeskCard();
};
#endif