#include <iostream>              //树
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int i=0;
struct BinaryNode
{
	int data;
	BinaryNode *left;
	BinaryNode *right;
};
class BinaryTree
{
private:
	BinaryNode *root;
public:
	explicit BinaryTree();
	BinaryNode * createBTree();
	virtual ~BinaryTree();
	void deleteBTree(BinaryNode *root);
	BinaryNode * returnroot();
	void setroot(BinaryNode *r);
	void preorder(BinaryNode *root);  //前序遍历
	void inorder(BinaryNode *root);   //中序遍历
	void postorder(BinaryNode *root); //后序遍历
	int BTreeSize(BinaryNode *r);  //求节点个数
	int BTreeleaves(BinaryNode *r);  //求叶子节点数
	//int BTreeHeight(BinaryNode *r);  //求树高
	int BTreeDepth(BinaryNode *r);   //求深度
	void addTreeNode(BinaryNode *r,BinaryNode *node);  //添加节点
	BinaryNode * findTreeNode(BinaryNode *r,int data);
	void DFS(BinaryNode *root);   //深度优先遍历
	void BFS(BinaryNode *root);    //广度优先遍历
};
BinaryTree::BinaryTree()
{
	this->root=createBTree();
}
BinaryNode * BinaryTree::createBTree()
{

	BinaryNode *T;
	int c;
	cin>>c;
	if(c==-1)
	{
		T=NULL;
	}
	else
	{
		T=new BinaryNode;
		T->data=c;
		T->left=NULL;
		T->right=NULL;
		if(i==0)
		{
			root=T;
			i++;
		}
		T->left=createBTree();
		T->right=createBTree();
	}
	return T;
}
BinaryTree::~BinaryTree()
{
}
void BinaryTree::deleteBTree(BinaryNode *root)
{
	if(root==NULL)
	
		return;
	else
	{
		deleteBTree(root->left);
		deleteBTree(root->right);
		delete root;
		root=NULL;
	}
}
BinaryNode * BinaryTree::returnroot()
{
	return root;
}
void BinaryTree::setroot(BinaryNode *r)
{
	root=r;
}
void BinaryTree::preorder(BinaryNode *r)
{
	if(r!=NULL)
	{
		cout<<r->data;
		preorder(r->left);
		preorder(r->right);
	}
}
void BinaryTree::inorder(BinaryNode *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		cout<<r->data;
		inorder(r->right);
	}
}
void BinaryTree::postorder(BinaryNode *r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		cout<<r->data;
	}
}
int BinaryTree::BTreeSize(BinaryNode *r)
{
	if(r==NULL)
		return 0;
	else
		return 1+BTreeSize(r->left)+BTreeSize(r->right);
}
int BinaryTree::BTreeleaves(BinaryNode *r)
{
	if(r==NULL)
		return 0;
	else
	{
		if(r->left==NULL&&r->right==NULL)
			return 1;
		else
			return(BTreeleaves(r->left)+BTreeleaves(r->right));
	}
}
//int BinaryTree::BTreeHeight(BinaryNode *r)
//{
//	if(r==NULL)
//		return 0;
//	else
//	{
//		int m=BTreeHeight(r->left);
//		int n=BTreeHeight(r->right);
//		return (m>n)?m+1:n+1;
//	}
//}
int BinaryTree::BTreeDepth(BinaryNode *r)
{
	if(r==NULL)
		return 0;
	else
	{
		int m=BTreeDepth(r->left);
		int n=BTreeDepth(r->right);
		return (m>n)?m+1:n+1;
	}
}
BinaryNode *BinaryTree::findTreeNode(BinaryNode *r,int data)
{
	BinaryNode *p=NULL;
	if(r==NULL)
	{
		return NULL;
	}
	else
	{
		if(r->data==data)
			return r;
		else
			if(p=findTreeNode(r->left,data))
			{
				return p;
			}
			else if(p=findTreeNode(r->right,data))
				return p;
			else
				return NULL;
	}
}
void BinaryTree::addTreeNode(BinaryNode *r,BinaryNode *node)
{
	BinaryNode *parent;
	int data;
	node->left=NULL;
	node->right=NULL;
	cout<<"输入该结点父亲数据："<<endl;
	cin>>data;
	parent=findTreeNode(r,data);
	if(!parent)
	{
		cout<<"没有该父亲。"<<endl;
		return;
	}
	cout<<"1、添加该节点到左子树；2、添加该节点到右子树。"<<endl;
	int input;
	do
	{
		cin>>input;
		if(input==1||input==2)
		{
			switch(input)
			{
			case 1:
				if(parent->left)
				{
					cout<<"左子树不为空。"<<endl;
				}
				else
				{
					parent->left=node;
					cout<<"数据添加成功！"<<endl;
				}
				break;
			case 2:
				if(parent->right)
				{
					cout<<"右子树不为空。"<<endl;
				}
				else
				{
					parent->right=node;
					cout<<"数据添加成功！"<<endl;
				}
				break;
			default:
				cout<<"选择错误！"<<endl;
				break;
			}
		}
	}while(input!=1&&input!=2);
}
void BinaryTree::DFS(BinaryNode *root)
{
	if(root!=NULL)
	{
		stack<BinaryNode *> nodestack;
		nodestack.push(root);
		BinaryNode *node;
		while(!nodestack.empty())
		{
			node=nodestack.top();
			cout<<node->data;
			nodestack.pop();
			if(node->right)
			{
				nodestack.push(node->right);
			}
			if(node->left)
			{
				nodestack.push(node->left);
			}
		}
	}
	else
		return;
}
void BinaryTree::BFS(BinaryNode *root)
{
	if(root!=NULL)
	{
		queue<BinaryNode *> nodequeue;
		nodequeue.push(root);
		BinaryNode *node;
		while(!nodequeue.empty())
		{
			node=nodequeue.front();
			nodequeue.pop();
			cout<<node->data;
			if(node->left)
			{
				nodequeue.push(node->left);
			}
			if(node->right)
			{
				nodequeue.push(node->right);
			}
		}
	}
	else
		return;
}
int main()
{
	BinaryTree *BT=new BinaryTree;
	BinaryNode *T=NULL;
	cout<<"已建立树："<<endl;
	cout<<"前序遍历："<<endl;
	BT->preorder(BT->returnroot());
	cout<<endl;
	cout<<"中序遍历："<<endl;
	BT->inorder(BT->returnroot());
	cout<<endl;
	cout<<"后序遍历："<<endl;
	BT->postorder(BT->returnroot());
	cout<<endl;
	cout<<"叶子节点数："<<BT->BTreeleaves(BT->returnroot())<<endl;
	cout<<"节点数："<<BT->BTreeSize(BT->returnroot())<<endl;
	cout<<"深度优先遍历："<<endl;
	BT->DFS(BT->returnroot());
	cout<<endl;
	cout<<"广度优先遍历："<<endl;
	BT->BFS(BT->returnroot());
	cout<<endl;
	cout<<"插入节点："<<endl;
	BinaryNode *n=new BinaryNode;
	cout<<"输入插入数据：";
	int data;
	cin>>data;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	BT->addTreeNode(BT->returnroot(),n);
	return 0;
}
