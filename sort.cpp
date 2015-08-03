#include <iostream>              //各种排序方法
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
class sort
{
public:
	void insertsort(vector<int> &a);   //插入排序
	void shellsort(vector<int> &a);    //希尔排序,主要是增量的选择，一般来说第一次取总长度的一半,第二次取一半的一半,依次累推直到1为止
	void heapsort(vector<int> &a);     //小到大堆排序，大顶堆
	void heapadjust(vector<int> &a,int s,int n);  //大顶堆调整
	void buildingheap(vector<int> &a);     //构造堆  
	void merge(vector<int> &a,vector<int> &tmp,int leftpos,int rightpos,int rightend);
	void mergesort(vector<int> &a,vector<int> &tmp,int left,int right);   //归并排序
	void qsort(vector<int> &a,int low,int high);     //快速排序
};
void sort::insertsort(vector<int> &a)
{
	int temp;
	int j;
	for(int i=1;i<a.size();i++)
	{
		temp=a[i];
		for(j=i;j>0&&temp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=temp;
	}
}
void sort::shellsort(vector<int> &a)   //分段直接插入
{
	for(int gap=a.size()/2;gap>0;gap=gap/2)
		for(int i=gap;i<a.size();i++)
		{
			int tmp=a[i];
			int j;
			for(j=i;j>=gap&&tmp<a[j-gap];j=j-gap)
				a[j]=a[j-gap];
			a[j]=tmp;
		}
}
void sort::heapadjust(vector<int> &a,int s,int n)
{
	int tmp=a[s];
	int child=2*s+1;           //左孩子
	while(child<n)
	{
		if(child+1<n&&a[child]<a[child+1])        //右孩子大于左孩子
		{
			++child;
		}
		if(a[s]<a[child])    //子节点大于父节点
		{
			a[s]=a[child];
			s=child;
			child=2*s+1;
		}
		else
			break;
		a[s]=tmp;
	}
}
void sort::buildingheap(vector<int> &a)
{
	for(int i=(a.size()-1)/2;i>=0;--i)
		heapadjust(a,i,a.size());
}
void sort::heapsort(vector<int> &a)
{
	buildingheap(a);
	for(int i=a.size()-1;i>0;--i)
	{
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapadjust(a,0,i);
	}
}
void sort::merge(vector<int> &a,vector<int> &tmp,int leftpos,int rightpos,int rightend)
{
	int leftend=rightpos-1;  
	int tmppos=leftpos;
	int num=rightend-leftpos+1;
	while(leftpos<=leftend&&rightpos<=rightend)
		if(a[leftpos]<=a[rightpos])
			tmp[tmppos++]=a[leftpos++];
		else
			tmp[tmppos++]=a[rightpos++];
	while(leftpos<=leftend)
		tmp[tmppos++]=a[leftpos++];
	while(rightpos<=rightend)
		tmp[tmppos++]=a[rightpos++];
	for(int i=0;i<num;i++,rightend--)
		a[rightend]=tmp[rightend];
}
void sort::mergesort(vector<int> &a,vector<int> &tmp,int left,int right)
{
	if(left<right)
	{
		int center=(left+right)/2;
		mergesort(a,tmp,left,center);
		mergesort(a,tmp,center+1,right);
		merge(a,tmp,left,center+1,right);
	}
}
void sort::qsort(vector<int> &a,int low,int high)
{
	int first=low;
	int last=high;
	int key=a[first];
	if(low>=high)
		return;
	while(first<last)
	{
		while(a[last]>=key)
			--last;
		a[first]=a[last];
		while(a[first]<=key)
			++first;
		a[last]=a[first];
	}
	a[first]=key;
	qsort(a,low,first-1);
	qsort(a,first+1,high);
}