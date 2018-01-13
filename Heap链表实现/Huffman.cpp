#include <iostream>
#include <cstring>
#include <string>
#include "HuffmanTree.h"

using namespace std;

int main()
{
	HuffmanTree tree;
	cout<<"����������Ҫ������ַ�����:";
	int n;
	cin>>n;
	 
	char str[n];
	int num[n];
	
	cout<<"����������Ҫ������ַ�:";
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	cout<<"����������ַ��Ķ�ӦƵ��:";
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	
	tree.CreateTree(str,num,n);
	tree.Print();
}
