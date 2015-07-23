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
	int setCardToTop(Card * card);//���ǵȼ��ܿ���
	int setCardToUnder(Card *card);
	int setCardToUsed(Card *card);   //�����������ƶ�
	int setCardToProcess(Card *card); //��Ϸ�����������ڳ��ϵ���
	vector<Card *> getAllProcessCard();
	Card *getTopProcessCard();
	void moveProcessToUsed();
	void eraseAllProcessCard();
	int CardNum();
	void testPrintDeskCard();
};
#endif