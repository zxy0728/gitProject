#include <iostream>
using namespace std;
int yuesefu(int n,int k,int m);
int main()
{
	int n,k,m,num;
	cin>>n>>k>>m;
	num=yuesefu(n,k,m);
	cout<<"剩下的人是"<<num<<endl;
	return 0;
}
int yuesefu(int n,int k,int m)
{
	int last=0;
	for(int i=2;i<=n;i++)
	{
		last=(last+m+k-1)%i;
	}
	return last+1;
}
