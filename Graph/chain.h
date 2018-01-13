#ifndef CHAIN_H_
#define CHAIN_H_

#include "xcept.h"
#include "chainnode.h"
#include <iostream>
using namespace std;

template <class T> class ChainIterator;

template<class T>
class Chain
{
	friend ChainIterator<T>;

	public:
		Chain()
		{
			//��ʾһ����ָ�룬http://www.cnblogs.com/fly1988happy/archive/2012/04/16/2452021.html 
			first = 0; 
		}
		~Chain();
		bool IsEmpty() const
		{
			return first==0;
		}
		int Length() const;
		//Find----�ҵ������k��Ԫ���У��ڷ���true�����ڷ���false��ͬʱ����k��Ԫ�ص�value����data 
		//���Ӷ�Ϊ O(k) 
		bool Find(int k,T& data) const;
		//Search----�ҵ�data��Ԫ����λ�ã����ڷ���-1 
		//���Ӷ�Ϊ T(n) 
		int Search(T& data) const;
		//Delte----��data��Ϊ��k��Ԫ�ص�value����ɾ���� 
		//���Ӷ�Ϊ O(k) 
		Chain<T>& Delete(int k,T& data);
		//Delete--������������λ��ɾ��������������������ɾ�� 
		//���Ӷ�Ϊ T(n) 
		Chain<T>& Delete(T& data); 
		//Insert-----�ڵ�k��Ԫ�غ����data 
		//���Ӷ�Ϊ O(k) 
		Chain<T>& Insert(int k,T& data);

		//Output----������� 
		void Output(ostream& out) const;
		//Erase----������ȫ����� 
		//���Ӷ�Ϊ O(n) 
		void Erase();
		//Append----������������һ��Ԫ�� 
		//���Ӷ�Ϊ O(n) 
		Chain<T>& Append(const T&x);
		ChainNode<T>* First();
	private:
		ChainNode<T>* first;
		//first��ָ���һ��Ԫ�ص�ָ�� 
		int MaxSize;
};

template<class T>
Chain<T>::~Chain()
{
	ChainNode<T>* next;
	while(first)
	{
		next = first->link; 
		delete first;
		//delete Ҫɾ���Ķ��������new������ 
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const
{
	ChainNode<T>* current = first;
	int length=0;
	while(current)
	{
		current = current->link;
		length++;
	}
	
	return length;
}

template<class T>
bool Chain<T>::Find(int k,T& data) const
{
	
	if(k<1)	return false;
	//���һ��ʼû���뵽������
	
	ChainNode<T>* current = first;
	
	k--;
	while(current&&k)
	{
		k--;
		current = current->link;
	}
	
	if(k)	return false;
	
	data = current->data; 
	return true;
}

template<class T>
int Chain<T>::Search(T& data) const
{
	ChainNode<T>* current = first;
	//������û��*��ʲô��ͬ-----ָ��ѽ���϶���ָ����ָ����� 
	int index = 1; 
	while(current)
	{
		if(current->data == data)
		{
			return index;
		}
		current = current->link;
		index++;	
	}
	
	return 0;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k,T& data)
{
	if(k<1)	throw OutOfBounds(); 
	ChainNode<T>* current = first;
	
	ChainNode<T>* insertNode = new ChainNode<T>;
	insertNode->link = 0;
	//Ϊʲônull�Ͳ���---nullҲ�ǶԵģ�����Ҫ��д 
	insertNode->data = data;
	
	if(k==1)
	{
		insertNode->link = first;
		first = insertNode;
	}else
	{
		for(int i=1;i<k&&current;i++)
		{
			current = current->link;
		}
	
		if(!current) throw OutOfBounds();
		
		//Ϊʲô����������������֮ǰ��first����Ҳ�ı��� 
		insertNode->link = current->link;
		current->link = insertNode;
		
	}
	
	return *this;
	//��ס���return����ʽ 
}

template<class T>
Chain<T>& Chain<T>::Delete(int k,T& data)
{
	if(k<1)	throw OutOfBounds();
	
	if(k==1)
	{
		data = first->data;
		ChainNode<T> *current = first->link;
		delete first;
		first = current;
		
	}else
	{
		ChainNode<T>* current = first;
		ChainNode<T>* previous = first;
		for(int i=1;i<k-1&&previous;i++)
		{
			previous = previous->link;
		}
		
		current = previous->link;

		if(!current)	throw OutOfBounds();
		previous->link = current->link;
		data = current->data;
		delete current;
		
	}
	
	return *this;
}

template <class T>
Chain<T>& Chain<T>::Delete(T &d)
{
	ChainNode<T>* current = first;
	ChainNode<T>* previous = first;
	while(current)
	{
		if(current->data == d)
		{
			previous->link = current->link;
			current->link = 0;
			delete current;
			return *this;
		}
		previous = current;
		current = current->link;
	}
	
	cout<<"ɾ��ʧ��"<<endl;
	return *this;
}

template <class T>
void Chain<T>::Erase()
{
	ChainNode<T>* current = first;
	while(current)
	{
		current = first->link;
		delete first;
		first = current;
	}
}

template<class T>
Chain<T>& Chain<T>::Append(const T& data)
{
	if(!first)
	{
	//	first->data = data;
		ChainNode<T>* insertNode = new ChainNode<T>;
		insertNode->link = 0;
		insertNode->data = data;
		first = insertNode;
	}else
	{
		ChainNode<T>* current;
		current = first;
		
		while(current->link)
		{
			current = current->link;
		}
		ChainNode<T>* insertNode = new ChainNode<T>;
		insertNode->data = data;
		insertNode->link = 0; 
		current->link = insertNode;
	}
	
	return *this;
}

template<class T>
void Chain<T>::Output(ostream& out) const
{
	ChainNode<T>* current = first;
	while(current)
	{
		out << current->data << " ";
		current = current->link;
	}
}

template<class T>
ostream& operator<<(ostream& out,const Chain<T>&x)
{
	x.Output(out);
	return out;
}

template <class T>
ChainNode<T>* Chain<T>::First()
{
	return first;
}
#endif
