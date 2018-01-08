#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

template <class K,class E>
class HashTable
{
	public:
		HashTable();
		HashTable(int d);
		~HashTable(){};
		
		//�ҵ�keyֵ��λ�� 
		int Pos(const K& k);
		//��keyֵΪk��ֵ���ظ�E 
		bool Search(const K& k,E &e);
		//��keyֵΪK��ֵɾ��,���ظ�E 
		HashTable<K,E>& Delete(const K& k,E& e);
		//����Eֵ 
		HashTable<K,E>& Insert(const E& e);
	private:
		bool *empty;
		E *save;
		int D;
};

template <class K,class E>
HashTable<K,E>::HashTable()
{
	D = 0;
}

template <class K,class E>
HashTable<K,E>::HashTable(int d)
{
	D = d;
	empty = new bool[D];
	save = new E[D];
	
	for(int i=0;i<D;i++)
	{
		empty[i] = true;
	}
	//Ϊʲô���� new TableNode<T>[D]();
}

template <class K,class E>
//����keyֵΪK��λ�� 
int HashTable<K,E>::Pos(const K& k)
{
	int i = k%D;
	int pos = i;
	while(save[pos]!=k && !empty[pos])
	{
		pos = (pos+1)%D;
		if(pos==i) break;
	}
	
	return pos;
}

template <class K,class E>
//����keyֵ�ҵ�Ԫ�� 
bool HashTable<K,E>::Search(const K& k,E &e)
{
	int pos = Pos(k);
	if(empty[pos] || save[pos]!=k)
	{
		//ʧ��������ڿ�λ��ͣ�£������ڴ���λ��ͣ��
		return false;
	}
	
	e = save[pos];
	return true;
}

template <class K,class E>
HashTable<K,E>& HashTable<K,E>::Insert(const E& e)
{
	K key = e;
	int pos = Pos(key);
	if(empty[pos])
	{
		save[pos] = e;
		empty[pos] = false;
	}
	
	return *this;
	
	//������ǿգ����������
	//��һ��Ϊ��ǰλ��ȷʵΪK����˵�������e������(ע��ÿ����Ӧ��key��Ψһ��
	//�ڶ���Ϊ��ǰλ�ò���K����˵������һȦû�ҵ����KEY����֮�أ���˵�����Ѿ����ˡ� 
//	if(save[pos]==k) 
//	
}


template <class K,class E>
HashTable<K,E>& HashTable<K,E>::Delete(const K& k,E& e)
{
	int pos = Pos(k);
	if(empty[pos] || save[pos]!=k)
	{
		//ʧ��������ڿ�λ��ͣ�£������ڴ���λ��ͣ��
		//ʧ��,����һЩ˵�� 
		return *this;
	}
	
	e = save[pos];
	save[pos] = 0;
	return *this;
}

#endif
