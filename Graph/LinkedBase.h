#ifndef LINKEDBASE_H_
#define LINKEDBASE_H_

#include <iostream>
#include <cstring>
#include <string>
#include "chain.h"
using namespace std;

//����ʵ�֣���Ȩ����ͼ-->��Ȩ����ͼ����Ȩ����ͼ-->��Ȩ����ͼ 
template <class T>
class LinkedBase
{
	public:
		LinkedBase(int vertice = 10);
		~LinkedBase(){}
		
		int Edges(){return e;}
		int Vertices(){return n;}

		int InDegree(int i);
	protected:
		int n;
		int e;
		Chain<T> *chain;
};

template <class T>
LinkedBase<T>::LinkedBase(int vertice)
{
	n = vertice;
	e = 0;
	chain = new Chain<T> [n+1];//chain[0]���� 
}

template <class T>
int LinkedBase<T>::InDegree(int i)
{
	return chain[i]->Length();
}
#endif
