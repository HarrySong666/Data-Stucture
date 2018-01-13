#ifndef MAXHEAP_H_
#define MAXHEAP_H_
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include "HeapNode.h"
using namespace std;
template <class T>
class MaxHeap
{
	public:
		MaxHeap();
		MaxHeap(T &data);
		~MaxHeap(){};
		
		MaxHeap<T>& Insert(const T &data);
		T& Delete();
		
		void Initialize(T *input,int n);
		
		//����ѣ���Ϊ����������ֱ����������������ǵı��� 
		void PreOutput();
		void InfixOutput();
		void PostOutput();
		void Print();
	private:
		HeapNode<T> *root;
		void PreOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp));
		void PostOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp));
		void InOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp));
		
		static void Output(HeapNode<T> *current);
		void print(HeapNode<T> *current,int pre);
};

template <class T>
MaxHeap<T>::MaxHeap()
{
	root = 0;
}

template <class T>
MaxHeap<T>::MaxHeap(T &d)
{
	root = new HeapNode<T>(d);
}
template <class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T &data)
{
	//Ҫ����Ľڵ�
	HeapNode<T> *x = new HeapNode<T>(data);
	
	if(!root)
	{
		root = x;
		return *this;
	} 
	//����һ�����У����ڲ�α���(LevelOrder) 
	queue<HeapNode<T>* > Q;
	Q.push(root);
	
	HeapNode<T> *current = Q.front();
	while(current)
	{ 
		if(!current->leftChild)
		{
			current->leftChild = x;
			x->father = current;
		}else if(!current->rightChild)
		{
			current->rightChild = x;
			x->father = current;
		}else
		{
			Q.push(current->leftChild);
			Q.push(current->rightChild);
			
			//���ж��е���һ��Ԫ��
			Q.pop();
		 	current = Q.front();
		 	continue;
		}
		
		//���е���һ��˵��Ҫ����Ľڵ��Ѿ�������
		current = x;
		while(current->father && current->data > current->father->data)
		{
			//�븸�׽���λ��
			T temp = current->father->data;
			current->father->data = current->data;
			current->data = temp; 
			
			current = current->father;
		} 
		break;
	}
	
	return *this;
}

template <class T>
T& MaxHeap<T>::Delete()
{
//	if(root==NULL)	return ;
	T data = root->data;
	if(!root->leftChild)	return data;
	//���ҳ����һ���ڵ�
	queue<HeapNode<T>* > Q;
	Q.push(root);
	
	HeapNode<T> *previous = root;
	HeapNode<T> *current = root;
	while(current)
	{
		int temp_current = current->data;
		int temp_x = previous->data;
		//���û����ڵ㣬��˵����queue��һ��Ԫ�ص��ҽڵ������һ�� 
		if(!current->leftChild)
		{
			HeapNode<T> *right = previous->rightChild;
			root->data = right->data;
			//previous->rightChild->father = 0;
			//�и����ʣ�������ʽ��ָ�����ҽڵ��father���ԣ�����ָ�����ҽڵ��father����
			right->father = 0;
			previous->rightChild = 0;
			delete right; 
		}else if(!current->rightChild)
		{
			//���û���ҽڵ㣬��˵����queue��ǰԪ�ص���ڵ������һ��
			HeapNode<T> *left = current->leftChild;
			root->data = left->data;
			left->father = 0;
			current->leftChild = 0;
			delete left; 
		}else
		{
			Q.push(current->leftChild);
			Q.push(current->rightChild);
			
			previous = current;
			Q.pop();
			current = Q.front();
			
			continue;
		}
		
		//���Ӹ��ڵ㿪ʼ������ֵ����
		current = root;
		while(current->leftChild)
		{
			//Ϊ�˼�࣬����һ��������0��ʾ������1��ʾ����ڵ㻻��2��ʾ���ҽڵ㻻 
			int swap = 0;
			//���û���ҽڵ㣬ֱ������ڵ�Ƚ� 
			if(!current->rightChild)
			{
				//�������ڵ�С������ 
				if(current->data < current->leftChild->data)	swap = 1;
			}else
			{
				//��ڵ���ҽڵ������ڵ�Ƚϣ��������ҽڵ�Ƚ� 
				if(current->leftChild->data > current->rightChild->data)
				{
					if(current->data < current->leftChild->data)	swap = 1;
				}else
				{
					if(current->data < current->rightChild->data)	swap = 2;
				}
			}
			
			if(swap==1)
			{
				T temp = current->leftChild->data;
				current->leftChild->data = current->data;
				current->data = temp;
				
				current = current->leftChild;
			}else if(swap==2)
			{
				T temp = current->rightChild->data;
				current->rightChild->data = current->data;
				current->data = temp;
				
				current = current->rightChild;
			}else 
			{
				break;
			}
		}
		break;
	}
	return data;
}

template <class T>
void MaxHeap<T>::Initialize(T *input,int n)
{
	//���ȸ���input�����ʼ��һ��������
	queue<HeapNode<T>* > Q;
	stack<HeapNode<T>* > S;
	root = new HeapNode<T>(input[0]);
	Q.push(root);
	HeapNode<T> *current = Q.front();

	int left = 1;//left��ʾҪ����Ľڵ��Ƿ�Ӧ�ò���current����� 
	for(int i=1;i<n;i++)
	{
		//Ҫ����Ľڵ� 
		HeapNode<T> *x = new HeapNode<T>(input[i]);
		Q.push(x);
		
		int temp_current = current->data;
		int temp_x = x->data;
		if(left)
		{
			S.push(current);
			current->leftChild = x;
			x->father = current;
			
			left = 0;
		}else
		{
			current->rightChild = x;
			x->father = current;
			
			left = 1;
			//current�Ѿ�������������һ���ڵ� 

			Q.pop();
			current = Q.front();
		
		}
	} 
	
	//������ϣ���current��ʼ�ж��Ƿ񽻻�����
	current = S.top();
	while(current)
	{
		while(current->leftChild || current->rightChild)
		{
			int swap = 0;
			//���û���ҽڵ㣬ֱ������ڵ�Ƚ� 
			if(!current->rightChild)
			{
				//�������ڵ�С������ 
				if(current->data < current->leftChild->data)	swap = 1;
			}else
			{
				//��ڵ���ҽڵ������ڵ�Ƚϣ��������ҽڵ�Ƚ� 
				if(current->leftChild->data > current->rightChild->data)
				{
					if(current->data < current->leftChild->data)	swap = 1;
				}else
				{
					if(current->data < current->rightChild->data)	swap = 2;
				}
			}
			
			if(swap==1)
			{
				T temp = current->leftChild->data;
				current->leftChild->data = current->data;
				current->data = temp;
				
				current = current->leftChild;
			}else if(swap==2)
			{
				T temp = current->rightChild->data;
				current->rightChild->data = current->data;
				current->data = temp;
				
				current = current->rightChild;
			}else 
			{
				
				break;
			}
		}
		
		S.pop();
		if(S.size())
			current = S.top();
		else 
			current = 0;
	}	
}

template <class T>
void MaxHeap<T>::PreOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp) )
{
	if(current)
	{
		visit(current);
		PreOrder(current->leftChild,visit);
		PreOrder(current->rightChild,visit);
	}
}

template <class T>
void MaxHeap<T>::InOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp))
{
	if(current)
	{
		InOrder(current->leftChild,visit);
		visit(current);
		InOrder(current->rightChild,visit);
	}
}

template <class T>
void MaxHeap<T>::PostOrder(HeapNode<T> *current,void(*visit)(HeapNode<T> *temp))
{
	if(current)
	{
		PostOrder(current->leftChild,visit);
		PostOrder(current->rightChild,visit);
		visit(current);
	}
}

template <class T>
void MaxHeap<T>::Output(HeapNode<T> *current)
{
	cout<<current->data<<" ";
}

template <class T>
void MaxHeap<T>::PostOutput()
{
	PostOrder(root,Output);
}

template <class T>
void MaxHeap<T>::InfixOutput()
{
	InOrder(root,Output);
}

template <class T>
void MaxHeap<T>::PreOutput()
{
	PreOrder(root,Output);
}

template <class T>
void MaxHeap<T>::print(HeapNode<T> *current,int pre)
{
	if(current)
	{
		for(int i=0;i<pre;i++)
		{
			cout<<"--";
		}
		cout<<current->data<<endl;
		print(current->leftChild,pre+1);
		print(current->rightChild,pre+1);
	}
}

template <class T>
void MaxHeap<T>::Print()
{
	print(root,1);
}
#endif
