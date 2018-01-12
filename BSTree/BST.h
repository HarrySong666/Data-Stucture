#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <cstring>
#include <string>
#include "BinaryTree.h"
using namespace std;


template <class K,class E>
class BST : public BinaryTree<E>
{
	public:
		BST() : BinaryTree<E>(){};
		//�ҵ�keyֵΪK�Ľڵ㣬�Ҳ����򷵻�null 
		TreeNode<E>& Find(const K& k);
		//��keyֵΪK���ҵ������ظ�һ��E 
		bool Search(const K& k,E& e);
		//����e 
		BST<K,E>& Insert(const E& e);
		//����keyֵɾ���ڵ� 
		BST<K,E>& Delete(const K&k,E &e);
		
};

template <class K,class E>
TreeNode<E>& BST<K,E>::Find(const K& k)
{
	TreeNode<E> *current = this->root;
	//��Ҫ��д!=���� 
	while(current->data != k)
	{
		if(current->data < k)
		{
			current = current->rightChild;
		}else
		{
			current = current->leftChild;
		}
		
		if(!current) return NULL;
	}
	
	return current;
}

template <class K,class E>
bool BST<K,E>::Search(const K& k,E& e)
{
	TreeNode<E> *current = Find(k);
	if(current)
	{
		e = current->data;
		return true;
	} 
	return false;
}

template <class K,class E>
BST<K,E>& BST<K,E>::Insert(const E& e)
{
	//��д��ֵ���� 
	K key = e;
	TreeNode<E> *current = this->root;
	
	if(!current) 
	{
		this->root = new TreeNode<E>(e);
		return *this;
	}
	while(true)
	{
		if(current->data < key)
		{
			if(current->rightChild)
			{
				current = current->rightChild;
			}else
			{
				current->rightChild = new TreeNode<E>(e);
				break;
			}
		}else
		{
			if(current->leftChild)
			{
				current = current->leftChild;
			}else
			{
				current->leftChild = new TreeNode<E>(e);
				break;
			}
		}
	} 
	
	return *this;
}

template <class K,class E>
BST<K,E>& BST<K,E>::Delete(const K& k,E& e)
{
	TreeNode<E> *current = this->root;
	TreeNode<E> *previous = current;
	while(current && current->data!=k)
	{
		previous = current;
		if(current->data < k)
		{
			current = current->rightChild;
		}else
		{
			current = current->leftChild;
		}
	}
	
	e = current->data;
	//�쳣�����������Ҳ���������key 
	//if(!current)

	//Ҫɾ���ĵ���Ҷ�ӽڵ㣬ֱ��ɾ������. 
	if(!current->leftChild && !current->rightChild)
	{
		//ֱ��current�Ƿ����?current = 0 
		if(current == previous->rightChild)
			previous->rightChild = 0;
		else
			previous->leftChild = 0;
			
		delete current;
	}else if(current->leftChild && current->rightChild)
	{
		//�ҵ����������ҵĽڵ� 
		TreeNode<E> *temp_father = current->leftChild;
		TreeNode<E> *temp_child = current->leftChild;
		
		while(temp_child->rightChild)
		{
			temp_father = temp_child;
			temp_child = temp_child->rightChild;
		}
		
		current->data = temp_child->data;

		temp_father->rightChild = temp_child->leftChild;
		temp_child->leftChild = 0;
		
		if(temp_father==temp_child) current->leftChild = temp_father->leftChild;
		delete temp_child;
	}else if(current->leftChild)
	{
		if(current == previous->rightChild)
			previous->rightChild = current->leftChild;
		else
			previous->leftChild = current->leftChild;
			
		delete current;
	}else
	{
		if(current == previous->leftChild)
			previous->leftChild = current->rightChild;
		else
			previous->rightChild = current->rightChild;
			
		delete current;
	}
	
	return *this;
}

#endif
