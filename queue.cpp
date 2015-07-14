#include <iostream>              //队列，尾进头出
using namespace std;
struct node
{
	char data;
	node *next;
};
class queue
{
private:
	node *front;				//头
	node *rear;					//尾
public:
	explicit queue();
	virtual ~queue();
	bool rearpush(const char &e);
	bool frontpop(char &e);
	char getfront();
	char getrear();
	int size();
	bool isempty();
	void clear();
};
queue::queue()
{
	rear=new node;
	if(NULL==rear)
	{
		cout<<"队列内存分配失败。"<<endl;
		exit(1);
	}
	rear->next=NULL;
	rear->data=NULL;
	front=rear;
}
queue::~queue()
{
	clear();
}
bool queue::rearpush(const char &e)
{
	node *p=new node;
	if(NULL==p)
	{
		cout<<"内存分配失败。"<<endl;
		return false;
	}
	p->data=e;
	p->next=NULL;
	rear->next=p;
	rear=p;
	return true;
}
bool queue::frontpop(char &e)
{
	if(front==rear)
	{
		cout<<"队列为空。"<<endl;
		return false;
	}
	node *p=front->next;
	front->next=p->next;
	e=p->data;
	cout<<e<<endl;
	if(rear==p)
	{
		rear=front;
	}
	delete p;
	return true;
}
char queue::getfront()
{
	if(front==rear)
	{
		cout<<"队列为空。"<<endl;
		return NULL;
	}
	else
		return front->next->data;
}
char queue::getrear()
{
	if(front==rear)
	{
		cout<<"队列为空。"<<endl;
		return NULL;
	}
	else
		return rear->data;
}
int queue::size()
{
	node *p=front;
	int i=0;
	if(front==rear)
		return 0;
	else
		while(p!=rear)
		{
			p=p->next;
			i++;
		}
	return i;

}
bool queue::isempty()
{
	if(front==rear)
		return true;
	else
		return false;
}
void queue::clear()
{
	node *p=front;
	while(p)
	{
		p=p->next;
		delete front;
		front=p;
	}
	front=rear=NULL;
}
int main()
{
	int input;
	char x;
	queue q;
	do
	{
		cout<<"请输入想完成的任务："<<endl<<"1、压入一个元素"<<endl<<"2、弹出一个元素"<<endl<<"3、清空队列"<<endl<<"4、读取队列头元素"<<endl<<"5、读取队列尾元素"<<endl<<"6、打印队列的元素个数"<<endl<<"0、退出"<<endl;
		cin>>input;
		switch(input)
		{
		case 1:
			cout<<"请输入想要压入的元素:";
			cin>>x;
			q.rearpush(x);
			break;
		case 2:
			cout<<"弹出一个元素："<<endl;
			q.frontpop(x);
			cout<<x;
			break;
		case 3:
			q.clear();
			cout<<"已清空。"<<endl;
			break;
		case 4:
			cout<<"已读取队列头元素："<<endl;
			if(q.getfront()==NULL)
			{
				cout<<"空队列，没有队列元素。"<<endl;
			}
			else
				cout<<q.getfront()<<endl;
			break;
		case 5:
			cout<<"已读取队列尾元素："<<endl;
			if(q.getrear()==NULL)
			{
				cout<<"空队列，没有队列元素。"<<endl;
			}
			else
				cout<<q.getrear()<<endl;
			break;
		case 6:
			cout<<"栈中元素个数："<<q.size()<<endl;
			break;
		case 0:
			return 0;
		default:
			cout<<"请输入一个正确的数。"<<endl;
		}
	}while(input!=0);
}