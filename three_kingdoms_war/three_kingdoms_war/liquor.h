#pragma                              //�ƺ���ͨ�Ʋ�һ���������ܱ�����Ѫ��Ҳ�ܷǱ����˺�+1
#ifndef _LIQUOR_H_
#define _LIQUOR_H_
#include "card.h"
class Liquor:public Card       //��ʱ��ʹ�ã���Ҫ����ʹ�ù���
{
public:
	explicit Liquor(Suit _suit,string &_name,int _num);
	virtual ~Liquor();
};
#endif