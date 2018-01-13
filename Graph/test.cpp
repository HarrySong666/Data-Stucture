#include <iostream>
#include <cstring>
#include <string>
#include "GraphNode.h"
#include "chain.h"
#include "chainnode.h"
#include "xcept.h"
#include "LinkedBase.h"
#include "LinkedWDiGraph.h"
#include "LinkedWGraph.h"
#include "LinkedDiGraph.h"
#include "LinkedGraph.h"
#include "GraphNode.h"
#include "ChainIterator.h"
using namespace std;

template <class T>
void print(LinkedWDiGraph<T> &G,int vertices)
{
	cout<<"���������������ͼ�ı�"<<endl;
	cout<<"�����ʽ��A  B  C"<<endl;
	cout<<"����AΪ��ʼ��,BΪ�յ�,CΪȨֵ,ÿһ�μ����ʱ�밴�س���,����ʱ�����뵥��0"<<endl;
	int A,B,C;
	cin>>A>>B>>C;
	int e = 0; 
	while(A)
	{
		G.Add(A,B,C);
		e++;
		cin>>A;
		if(!A) break;
		cin>>B>>C;
	} 
	while(true)
	{
		
		cout<<"��ѡ����Ҫ���еĲ���"<<endl;
		cout<<"0.�˳�  1.��ĳ�������  2.���BFS���ɵ���  3.���DFS���ɵ���"<<endl;
		int m;
		cin>>m;
		if(m==1)
		{
			cout<<"��������Ҫ���ĸ��㿪ʼ����:";
			int i;
			cin>>i;
			G.IntializePos();
			int result = G.Begin(i);
			
			if(!result)
			{
				cout<<"���ź���û�дӸõ�����ı�"<<endl;
				cout<<endl;
				continue;
				//Ϊʲôbreak��ֱ���˳���? 
			}
			cout<<"�������Ϊ��";
			while(result)
			{
				cout<<result<<" ";
				result = G.NextVertex(i);
			}
			cout<<endl;
		}else if(m==2)
		{
			cout<<"��������Ҫ���ĸ��㿪ʼ����:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"�������:"<<endl;
			G.BFS(i,id,visit);
		}else if(m==3)
		{
			cout<<"��������Ҫ���ĸ��㿪ʼ����:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"�������"<<endl;
			G.DFS(i,visit,1);			
		}else if(m==0)
		{
			break;
		}else
		{
			cout<<"�����ʽ�Ƿ���"<<endl; 
		}
		
		cout<<endl;
	}
}

void print(LinkedDiGraph &G,int vertices)
{
	cout<<"���������������ͼ�ı�"<<endl;
	cout<<"�����ʽ��A  B"<<endl;
	cout<<"����AΪ��ʼ��,BΪ�յ�,ÿһ�μ����ʱ�밴�س���,����ʱ�����뵥��0"<<endl;
	int A,B;
	cin>>A>>B;
	int e = 0; 
	while(A)
	{
		G.Add(A,B);
		e++;
		cin>>A;
		if(!A) break;
		cin>>B;
	} 
	while(true)
	{
		
		cout<<"��ѡ����Ҫ���еĲ���"<<endl;
		cout<<"0.�˳�  1.��ĳ�������  2.���BFS���ɵ���  3.���DFS���ɵ���"<<endl;
		int m;
		cin>>m;
		if(m==1)
		{
			cout<<"��������Ҫ���ĸ��㿪ʼ����:";
			int i;
			cin>>i;
			G.IntializePos();
			int result = G.Begin(i);
			
			if(!result)
			{
				cout<<"���ź���û�дӸõ�����ı�"<<endl;
				cout<<endl;
				continue;
				//Ϊʲôbreak��ֱ���˳���? 
			}
			cout<<"�������Ϊ��";
			while(result)
			{
				cout<<result<<" ";
				result = G.NextVertex(i);
			}
			cout<<endl;
		}else if(m==2)
		{
			cout<<"��������Ҫ���ĸ��㿪ʼ����:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"�������:"<<endl;
			G.BFS(i,id,visit);
		}else if(m==3)
		{
			cout<<"��������Ҫ���ĸ��㿪ʼ����:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"�������"<<endl;
			G.DFS(i,visit,1);			
		}else if(m==0)
		{
			break;
		}else
		{
			cout<<"�����ʽ�Ƿ���"<<endl; 
		}
		
		cout<<endl;
	}	
}
int main()
{
	cout<<"��ѡ����Ҫ�����������͵�ͼ"<<endl;
	cout<<"1.�����Ȩͼ   2.�����Ȩͼ   3.������Ȩͼ   4.������Ȩͼ"<<endl;
	int n;
	cin>>n;
	cout<<"����������Ҫ������ͼ�ĵ�ĸ�����";
	int vertices;
	cin>>vertices;
	cout<<endl;
	if(n==1)
	{
		LinkedWDiGraph<int> G(vertices);
		print(G,vertices);
		
	}else if(n==2)
	{
		LinkedWGraph<int> G(vertices);
		print(G,vertices);
	}else if(n==3)
	{
		LinkedDiGraph G(vertices);
		print(G,vertices);
	}else if(n==4)
	{
		LinkedGraph G(vertices);
		print(G,vertices);
	}
}

