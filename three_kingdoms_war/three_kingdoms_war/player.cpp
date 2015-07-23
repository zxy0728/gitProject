#include "player.h"
#include "allcardheader.h"
Player::Player(deskCard * _deskcard,Service * _service,
		string _name,int _hp_max,Sex _sex,
		Nationality _nationality,int _SeatNo,Role _role):deskcard(_deskcard),
		service(_service),name(_name),hp_max(_hp_max),hp(_hp_max),sex(_sex),
		nationality(_nationality),period(noactive),SeatNo(_SeatNo),ChopUsed(false),
		alive(true),role(_role)
{
	EquipCard * equipped=NULL;
	for(int i=0;i<4;i++)
	{
		EquipmentCard.insert(EquipmentCard.begin(),equipped);
	}
	DelayTrick * detrick=NULL;
	JudgeCard.insert(JudgeCard.begin(),detrick);
	Card * hcard=NULL;
	handCard.insert(handCard.begin(),hcard);
}
Player::~Player()
{
}
void Player::getCard()
{
	service->getCardFromUnused(this);
}
void Player::setCardToPlace(Card *card,Place Where)
{
	if(card==NULL)
		return;
	switch(Where)
	{
	case judgeplace:
		{
			DelayTrick *dt=dynamic_cast<DelayTrick *>(card);
			JudgeCard.insert(JudgeCard.begin(),dt);
		}
		break;
	case equipplace:
		{
			EquipCard *ec=dynamic_cast<EquipCard *>(card);
			switch(ec->location())
			{
			case EquipCard::WeaponLocation:
				EquipmentCard[0]=ec;
			case EquipCard::ArmorLocation:
				EquipmentCard[1]=ec;
			case EquipCard::DefensiveHorseLocation:
				EquipmentCard[2]=ec;
			case EquipCard::OffensiveHorseLocation:
				EquipmentCard[3]=ec;
			}
			//EquipmentCard.insert(EquipmentCard.begin(),eq);
			break;
		}
	case handcardplace:
		handCard.insert(handCard.end(),card);
		break;		
	}
}
void Player::disCard()
{
	cout<<this->name<<"������:"<<endl;
	this->CheckHandCard();
	int no;
	cout<<"��������Ҫ�����ƺţ�";
	cin>>no;
	this->disCard(handcardplace,no-1);    //������Ŵ�1��ʼ������������0��ʼ
}
void Player::disCard(Place Where,int no)  //�������ص����ƺ�����0Ϊ��ſ�ʼ
{
	Card *card=NULL;
	switch(Where)
	{
	case handcardplace:
		if(handCard.size()==0)
			return;
		card=handCard[no];
		handCard.erase(handCard.begin()+no);
		break;
	case judgeplace:
		if(JudgeCard.size()==0)
			return;
		card=JudgeCard[no];
		JudgeCard.erase(JudgeCard.begin()+no);
		break;
	case equipplace:
		if(EquipmentCard.size()==0)
			return;
		card=EquipmentCard[no];
		//EquipmentCard.erase(EquipmentCard.begin()+no); //������erase����Ѻ���������±�ǰ��
		EquipmentCard[no]=NULL;   //ֻ����NULL����Ǹ�λ��
		break;
	}
	service->setCardToUsed(card);
}
void Player::disCard(Place Where,Card *card)  //��������ʲô�ƣ����������Ѱ����
{
	if(card==NULL)
		return;
	Card *throwcard=NULL;
	switch(Where)
	{
	case handcardplace:
		for(int i=0;i<handCard.size();i++)
		{
			if(handCard[i]==card)
			{
				throwcard=handCard[i];
				handCard.erase(handCard.begin()+i);
				break;
			}
		}
		break;
	case judgeplace:
		for(int i=0;i<JudgeCard.size();i++)
		{
			if(JudgeCard[i]==card)
			{
				throwcard=JudgeCard[i];
				JudgeCard.erase(JudgeCard.begin()+i);
				break;
			}
		}
		break;
	case equipplace:
		{
			EquipCard *ec=dynamic_cast<EquipCard *>(card);
			switch(ec->location())
			{
			case EquipCard::WeaponLocation:
				throwcard=EquipmentCard[0];
				EquipmentCard[0]=NULL;
				break;
			case EquipCard::ArmorLocation:
				throwcard=EquipmentCard[1];
				EquipmentCard[1]=NULL;
				break;
			case EquipCard::DefensiveHorseLocation:
				throwcard=EquipmentCard[2];
				EquipmentCard[2]=NULL;
				break;
			case EquipCard::OffensiveHorseLocation:
				throwcard=EquipmentCard[3];
				EquipmentCard[3]=NULL;
				break;
			}
		}
		break;
	}
	service->setCardToUsed(throwcard);
}
void Player::removeCard(Place Where,Card *card)
{
	if(card==NULL)
		return;
	switch(Where)
	{
	case handcardplace:
		for(int i=0;i<handCard.size();i++)
		{
			if(handCard[i]==card)
			{
				handCard.erase(handCard.begin()+i);
				break;
			}
		}
		break;
	case judgeplace:
		for(int i=0;i<JudgeCard.size();i++)
		{
			if(JudgeCard[i]==card)
			{
				JudgeCard.erase(JudgeCard.begin()+i);
				break;
			}
		}
		break;
	case equipplace:
		{
			EquipCard *ec=dynamic_cast<EquipCard *>(card);
			switch(ec->location())
			{
			case EquipCard::WeaponLocation:
				EquipmentCard[0]=NULL;
				break;
			case EquipCard::ArmorLocation:
				EquipmentCard[1]=NULL;
				break;
			case EquipCard::DefensiveHorseLocation:
				EquipmentCard[2]=NULL;
				break;
			case EquipCard::OffensiveHorseLocation:
				EquipmentCard[3]=NULL;
				break;
			}
		}
		break;
	}
}
Card *Player::returnCard(Place Where,int no)  //˳��
{
	Card *card=NULL;
	switch(Where)
	{
	case handcardplace:
		{
			if(handCard.size()==0)
				return NULL;
			card=handCard[no];
			handCard.erase(handCard.begin()+no);
		}
		break;
	case judgeplace:
		{
			if(JudgeCard.size()==0)
				return NULL;
			card=JudgeCard[no];
			JudgeCard.erase(JudgeCard.begin()+no);
		}
		break;
	case equipplace:
		{
			if((EquipmentCard[0]==NULL)&&(EquipmentCard[1]==NULL)&&(EquipmentCard[2]==NULL)&&(EquipmentCard[3]==NULL))
				return;
			card=EquipmentCard[no];
			EquipmentCard[no]=NULL;
		}
		break;
	}
	return card;
}
void Player::moveCardToProcess(Card *card)
{
	Card *throwcard=NULL;
	for(int i=0;i<handCard.size();i++)
	{
		if(handCard[i]==card)
		{
			throwcard=handCard[i];
			handCard.erase(handCard.begin()+i);
			break;
		}
	}
	deskCard->setCardToProcess(throwcard);
}
bool Player::askLeadCard(Cardtype cardtype)
{
	bool r=false;
	switch(cardtype)
	{
	case jinkt:
		{
			int no;
			cout<<this->name<<"�������"<<endl;
			cout<<this->name<<"���ƣ�"<<endl;
			this->CheckHandCard();
			cout<<this->name<<"������������ƺţ�������������0��";
			cin>>no;
			if(0==no)
				return false;
			if(handCard[no-1]->getName()=="��")
			{
				this->disCard(handcardplace,no-1);
				return true;
			}
			else
				return false;
		}
	case chopt:
		{
			int no;
			cout<<this->name<<"���ɱ��"<<endl;
			cout<<this->name<<"���ƣ�"<<endl;
			this->CheckHandCard
		}
		
	}
}