#include <iostream>
#include <cstring>
#include <string>

template <class K,class E>
class BST : public BinaryTree<E>
{
	public:
		BST();
		
		TreeNode<E>& Find(const K& k);
		//��keyֵΪK���ҵ������ظ�һ��E 
		bool Search(const K& k,E& e);
		//����e 
		void Insert(const E& e);
		//
		void Delete(const K&k,E &e);
	private:
		
}

template <class K,class E>
TreeNode<E>& BST::Find(const K& k)
{
	TreeNode<E> *current = root;
	//��Ҫ��д!=���� 
	while(current->data != k)
	{
		if(current->data < k)
		{
			current = current->right;
		}else
		{
			current = current->left;
		}
		
		if(!current) return null;
	}
	
	return current;
}

template <class K,class E>
bool BST::Search(const K& k,E& e)
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
BST<K,E>& BST::Insert(const E& e)
{
	//��д��ֵ���� 
	K key = e;
	TreeNode<E> *current = root;
	
	if(!root) root = new TreeNode<E>(e);
	while(true)
	{
		if(current->data < key)
		{
			if(current->right)
			{
				current = current->right;
			}else
			{
				current->right = new TreeNode<E>(e);
				break;
			}
		}else
		{
			if(current->left)
			{
				current = current->left;
			}else
			{
				current->left = new TreeNode<E>(e);
				break;
			}
		}
	} 
	
	return *this;
}

template <class K,class E>
BST<K,E>& BST::Delete(const K& k,E& e)
{
	TreeNode<E> *current = root;
	TreeNode<E> *previous = current;
	while(current && current->data!=k)
	{
		previous = current;
		if(current->data < k)
		{
			current = current->right;
		}else
		{
			current = current->right;
		}
	}
	
	e = current->data;
	//�쳣�����������Ҳ���������key 
	//if(!current)

	//Ҫɾ���ĵ���Ҷ�ӽڵ㣬ֱ��ɾ������. 
	if(!current->left && !current->right)
	{
		//ֱ��current�Ƿ����?current = 0 
		if(current == previous->right)
			previous->right = 0;
		else
			previous->left = 0;
			
		delete current;
	}else if(current->left && current->right)
	{
		//�ҵ����������ҵĽڵ� 
		TreeNode<E> *temp_father = current->left;
		TreeNode<E> *temp_child = current->left;
		
		while(temp_child->right)
		{
			temp_father = temp_child;
			temp_child = temp_child->right;
		}
		
		current->data = temp_child->data;
		 
		temp_child = temp_child->left;
		temp_father->right = temp_child;
		
		current = temp_father->right;
		delete current;
	}else if(current->left)
	{
		if(current == previous->right)
			previous->right = current->left;
		else
			previous->left = current->left;
			
		delete current;
	}else
	{
		if(current == previous->left)
			previous->left = current->right;
		else
			previous->right = current->right;
			
		delete current;
	}
	
	return *this;
}
