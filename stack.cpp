#include <iostream>              //栈
using namespace std;
int MaxSize;
template <typename T>
class stack
{
private:
	int size;                   //元素个数
	T *stackarray;              //存放的元素
	T *top;                    //栈顶
	T *bottom;                 //栈底
public:
	explicit stack(int MaxSize);
	virtual ~stack();
	bool push(const T &item);
	bool pop(T &item);
	int isempty();
	int isfull();
	void clear();
	T gettop();
	void printstack();
	const int returnsize() const;
};
template <typename T>
stack<T>::stack(int MaxSize)
{
	size=0;
	bottom=new T[MaxSize];
	if(NULL==bottom)
	{
		cout<<"空间分配失败。"<<endl;
		exit(1);
	}
	top=bottom;
}
template <typename T>
stack<T>::~stack()
{
	top=bottom;
	size=0;
	delete []bottom;
}
template <typename T>
bool stack<T>::push(const T &item)
{
	if(isfull()==0)
	{
		*top=item;
		top++;
		size++;
		return true;
	}
	else 
	{
		cout<<"栈已满。"<<endl;
		return false;
	}
}
template <typename T>
bool stack<T>::pop(T &item)
{
	if(isempty()==0)
	{
		top--;
		item=*top;
		size--;
		return true;
	}
	else
	{
		cout<<"栈为空。"<<endl;
		return false;
	}
}
template <typename T>
int stack<T>::isempty()
{
	if(top==bottom)
	{
		return 1;
	}
	else 
		return 0;
}
template <typename T>
int stack<T>::isfull()
{
	if(size==MaxSize)
	{
		return 1;
	}
	else
		return 0;
}
template <typename T>
void stack<T>::clear()
{
	size=0;
	top=bottom;
}
template <typename T>
T stack<T>::gettop()
{
	if(isempty()==0)
	{
		return *(top-1);
	}
	else
	{
		cout<<"栈已空。"<<endl;
		return 999;
	}
}
template <typename T>
void stack<T>::printstack()
{
	if(bottom==NULL)
	{
		cout<<"栈不存在。"<<endl;
	}
	else
	{
		for(int i=0;i<size;i++)
		{
			cout<<bottom[i]<<endl;
		}
	}
}
template <typename T>
const int stack<T>::returnsize() const
{
	return size;
}
int main()
{
	int input;
	int x;
	//int capa;
	cout<<"请输入想要创建的栈的大小：";
	cin>>MaxSize;
	stack<int> s(MaxSize);
	do
	{
		cout<<"请输入想完成的任务："<<endl<<"1、压入一个元素"<<endl<<"2、弹出一个元素"<<endl<<"3、清空栈"<<endl<<"4、读取栈顶元素"<<endl<<"5、打印栈中的元素"<<endl<<"6、打印栈的元素个数"<<endl<<"0、退出"<<endl;
		cin>>input;
		switch(input)
		{
		case 1:
			cout<<"请输入想要压入的元素:";
			cin>>x;
			s.push(x);
			break;
		case 2:
			cout<<"弹出一个元素："<<endl;
			s.pop(x);
			cout<<x;
			break;
		case 3:
			s.clear();
			cout<<"已清空。"<<endl;
			break;
		case 4:
			cout<<"已读取一个栈顶元素："<<endl;
			if(s.gettop()==999)
			{
				cout<<"空栈，没有栈顶元素。"<<endl;
			}
			else
				cout<<s.gettop()<<endl;
			break;
		case 5:
			cout<<"已打印栈中元素："<<endl;
			s.printstack();
			break;
		case 6:
			cout<<"栈中元素个数："<<s.returnsize()<<endl;
			break;
		case 0:
			return 0;
		default:
			cout<<"请输入一个正确的数。"<<endl;
		}
	}while(input!=0);
}