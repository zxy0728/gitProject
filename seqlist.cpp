#include <iostream>              //链表，顺序从0号开始
using namespace std;
//template <typename T>
class node
{
private:
	
	int data;
	node *next;
//	node *head;
public:
	friend class seqlist;
	node();
	node(int num,node *next1=NULL);
	node(node &node);
	virtual ~node();
	void setdata(int n);
	void setnext(node *p);
	const int getdata() const;
};
node::node()
{
}
node::node(int num,node *next1)
{
	data=num;
	next=next1; 
}
node::node(node &node)
{
	data=node.data;
	next=node.next;
}
node::~node()
{
}
void node::setdata(int n)
{
	data=n;
}
void node::setnext(node *p)
{
	next=p;
}
const int node::getdata() const
{
	return data;
}
class seqlist
{
private:
	node *head;
public:
	seqlist();
	seqlist(node *head1);
	virtual ~seqlist();
	node *locate(int pos);
	//int initlist();
	int insert(int n,int data);
	int remove(int n);
	void printlist();
	int findx(int x);
	void tailinsert(int x);
	void reverse();
//	int findkth(int i);
};
seqlist::seqlist()
{
	head=NULL;
}
seqlist::seqlist(node *head1)
{
	head=head1;
}
seqlist::~seqlist()
{
	node *p;
	p=head->next;
	while(p!=head)
	{
		node *q=p;
		p=p->next;
		delete q;
	}
	delete head;
}
int seqlist::insert(int n,int data1)
{
	node *p=locate(n);
	if(p==NULL)
	{
		return 0;
	}
	node *q=new node;
	q->data=data1;
	q->next=p->next;
	p->next=q;
	return 1;
}
int seqlist::remove(int n)
{
	node *p;
	p=locate(n);
	if((p==NULL)||(p->next==NULL))
	{
		return 0;
	}
	node *q;
	q=p->next;
	p->next=q->next;
	delete q;
	return 1;
}
void seqlist::printlist()
{
	node *p;
	p=head;
	if(head==NULL)
	{
		cout<<"该链表为空链表。"<<endl;
		return;
	}
	while(p->next!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data;
	cout<<endl;
}
int seqlist::findx(int x)
{
	node *p=head;
	int i=0;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			return i;
		}
		p=p->next;
		i++;
	}
	return -1;
}
node *seqlist::locate(int pos)
{
	int i=0;
	node *p=head;
	if(pos<0)
		return NULL;
	while((p!=NULL)&&(i<pos))
	{
		p=p->next;
		i++;
	}
	return p;
}
void seqlist::tailinsert(int x)
{
	//node *p=head;
	node *q=new node;
	q->data=x;
	q->next=NULL;
	if(head==NULL)
	{
		head=q;
		return;
	}
	node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;

}
void seqlist::reverse()
{
	if(head->next==NULL)
	{
		return;
	}
	if(head==NULL)
	{
		cout<<"链表为空链表。"<<endl;
		return;
	}
	node *pre=head;
	node *curr=pre->next;
	node *ne;
	while(curr)
	{
		ne=curr->next;
		curr->next=pre;
		pre=curr;
		curr=ne;
	}
	head->next=NULL;
	head=pre;
	
}
int main()
{
	int j=100;
	seqlist list;
	for(int i=0;j!=0;i++)
	{
		cout<<"请输入一个想完成的操作："<<endl<<"1、插入"<<endl<<"2、删除"<<endl<<"3、打印链表"<<endl<<"4、找出值为x的标号"<<endl<<"5、找出标号为i的值"<<endl<<"6、后插法"<<endl<<"7、链表反转"<<endl<<"0、退出"<<endl;
		cin>>j;
		switch(j)
		{
		case 0:
			return 0;
			//break;
		case 1:
			int loc1,num1;
			cout<<"请输入插入位置以及插入值：";
			cin>>loc1>>num1;
			list.insert(loc1,num1);
			break;
		case 2:
			int loc2;
			cout<<"请输入要删除的节点的位置：";
			cin>>loc2;
			list.remove(loc2);
			break;
		case 3:
			list.printlist();
			break;
		case 4:
			int num2;
			cout<<"请输入值x：";
			cin>>num2;
			cout<<list.findx(num2)<<endl;
			break;
		case 5:
			int num3;
			cout<<"请输入标号i：";
			cin>>num3;
			cout<<list.locate(num3)->getdata()<<endl;
			break;
		case 6:
			int num4;
			cout<<"请输入想插入的数据：";
			cin>>num4;
			list.tailinsert(num4);
			break;
		case 7:
			list.reverse();
			break;
		default:
			cout<<"请输入一个正确的数。"<<endl;
		}

		
	}
	
}

