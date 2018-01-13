#include <iostream>
#include <cstring>
#include <string>
#include "BinaryTree.h"
#include "Node.h"
using namespace std;

void visit(Node<int> *current)
{
	//current��ָ��һ��node��ָ�룬���Ҫ����ָ���Ǹ�node�ķ�����Ҫ��-> 
	cout<<current->returnData()<<" ";	
}

int main()
{
	
	BinaryTree<int> a;
	cout<<"����������Ҫ�����Ķ������Ľڵ���"<<endl;
	int n;
	cin>>n;
	cout<<"����������Ҫ�����Ķ�������ǰ�����"<<endl; 
	vector<int> input_1,input_2;

	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		input_1.push_back(temp);
	}
	cout<<"����������Ҫ�����Ķ��������������"<<endl; 
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		input_2.push_back(temp);
	}
	a.PreAndIn(input_1,input_2,0,n,0,n);
	cout<<"������������ϣ���ѡ�����²���"<<endl;
	cout<<"1.����������  2.����������  3.���ǰ�����  4.����߶�  5.��������Ŀ  0.����"<<endl;
	while(1)
	{
		cin>>n;
		if(n==1)
		{
			cout<<"�������Ϊ:";
			a.Postorder(visit);
			cout<<endl;
		}else if(n==2)
		{
			cout<<"�������Ϊ:";
			a.Inorder(visit);
			cout<<endl;
		}else if(n==3)
		{
			cout<<"ǰ�����Ϊ:";
			a.Preorder(visit);
			cout<<endl;
		}else if(n==4)
		{
			cout<<"�������߶�Ϊ:";
			cout<<a.countHeight(a.returnRoot())<<endl;
		}else if(n==5)
		{
			cout<<"�ڵ���ĿΪ:";
			cout<<a.countNode(a.returnRoot())<<endl;
		}else if(n==0)
		{
			break;
		}
	}
	

}
