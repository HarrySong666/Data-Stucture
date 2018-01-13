#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include "Node.h"
using namespace std;
//Using formula-based representation can make the space too wasteful.So,choose the linked.
//��Ҫѧϰ����private����Ӻ��� 
//template <class T,class K> BST;
template <class T> 
class BinaryTree
{
//	friend BST<T,K>;
	public:
		BinaryTree();
		~BinaryTree(){};
	
		//����--ʱ�临�Ӷ�T(n) 
		void Preorder(void (*visit)(Node<T>*visitNode));
		void Inorder(void (*visit)(Node<T>*visitNode));
		void Postorder(void (*visit)(Node<T>*visitNode));
		void Levelorder();
		
		//�ж϶������Ƿ�Ϊ�� 
		bool isEmpty();
		//���ظ��ڵ��data��x 
		bool Root(T &x);
		//����������Ľ����--�������ΪCountNode 
		int Size();
		//����������ĸ߶�--�������ΪCountHeight 
		int Height();
		
		Node<T>* returnRoot();
		//���������� 
		void MakeTree(const T &data,BinaryTree<T> &left,BinaryTree<T> &right);
		//��ٶ����� 
		void BreakTree(T &data,BinaryTree<T> &left,BinaryTree<T> &right);
		
		BinaryTree<T>& PreAndIn(vector<T> input_1,vector<T> input_2,int begin_1,int end_1,int begin_2,int end_2);
		
	private:
		Node<T> *root;
		//��ʾ����ʱ���е��Ľڵ��Լ��Ըýڵ�visitʱ�Ĳ��� 
		void Preorder(void (*visit)(Node<T>* visitNode),Node<T> *current);
		void Inorder(void (*visit)(Node<T>* visitNode),Node<T> *current);
		void Postorder(void (*visit)(Node<T>* visitNode),Node<T> *current);
		
		//�ڳ�����������ʹ����Щ������Ҫ��ø��ڵ�(private)�������Ҫ��������ڲ��������һ��Height()��Size()���� 
		int Height(Node<T> *current); 
		int Size(Node<T> *current);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = 0;
}

template <class T>
void BinaryTree<T>::Preorder(void (*visit)(Node<T>*visitNode))
{
	Preorder(visit,root);
}

template <class T>
void BinaryTree<T>::Inorder(void (*visit)(Node<T>*visitNode))
{
	Inorder(visit,root);
}

template <class T>
void BinaryTree<T>::Postorder(void (*visit)(Node<T>*visitNode))
{
	Postorder(visit,root);
}

template <class T>
void BinaryTree<T>::Preorder(void (*visit)(Node<T>*visitNode),Node<T> *current)
{
	if(current)
	{
		visit(current);
		Preorder(visit,current->leftChild);
		Preorder(visit,current->rightChild);
	}
		
}

template <class T>
void BinaryTree<T>::Inorder(void (*visit)(Node<T>*visitNode),Node<T> *current)
{
	if(current)
	{
		Inorder(visit,current->leftChild);
		visit(current);
		Inorder(visit,current->rightChild);
	}
	
}

template <class T>
void BinaryTree<T>::Postorder(void (*visit)(Node<T>*visitNode),Node<T> *current)
{
	if(current)
	{	
		Postorder(visit,current->leftChild);
		Postorder(visit,current->rightChild);
		visit(current);
	}

}

template <class T>
void BinaryTree<T>::MakeTree(const T &data,BinaryTree<T> &left,BinaryTree<T> &right)
{
	root = new Node<T>(data);
//	cout<<root->data<<endl;
	root->leftChild = left.root;
	root->rightChild = right.root;
	
	//�ֱ���ָ��left��right��ָ���Ϊ0����ֻ�дӸ��ڵ�ſ��Է�������
	left.root = right.root = 0; 
}

template <class T>
Node<T>* BinaryTree<T>::returnRoot()
{
	return this->root;
}

//input1��ʾǰ�������input2��ʾ���������begin1��end1��ʾ��ǰҪ�����ǰ������ķ�Χ�����ʼ�Ϊ��ǰ������ǰ�����
//ͬ��begin2��end2��ʾ��ǰ������������� 
template <class T>
BinaryTree<T>& BinaryTree<T>::PreAndIn(vector<T> input_1,vector<T> input_2,int begin_1,int end_1,int begin_2,int end_2)
{
	if(end_1-begin_1 == 0)
	{
		BinaryTree<T>* temp = new BinaryTree<T>;
		return *temp;
	}
	int L,R;
	for(int i=begin_2;i<end_2;i++)
	{
		if(input_1[begin_1]==input_2[i])
		{
			L = i-begin_2;
			R = end_2-i-1;
			break;
		}
	}
	BinaryTree<T> left = PreAndIn(input_1,input_2,begin_1+1,begin_1+L+1,begin_2,begin_2+L);
	BinaryTree<T> right = PreAndIn(input_1,input_2,end_1-R,end_1,end_2-R,end_2);
	
	this->MakeTree(input_1[begin_1],left,right);
	return *this;
}

template <class T>
int BinaryTree<T>::Size(Node<T> *current)
{
	if(current)
	{
		return countNode(current->leftChild)+countNode(current->rightChild)+1;
	}else
	{
		return 0;
	}
}

template <class T>
int BinaryTree<T>::Size()
{
	return Size(root);
}
template <class T>
int BinaryTree<T>::Height(Node<T>*current)
{
	if(current)
	{
		return max(1+countHeight(current->leftChild),1+countHeight(current->rightChild));
	}else
	{
		return 0;
	}
}

template <class T>
int BinaryTree<T>::Height()
{
	return Height(root);
}
#endif
