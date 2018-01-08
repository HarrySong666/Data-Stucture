#ifndef HASHVALUE_H_
#define HASHVALUE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class K,class T>
class HashValue
{
	public:
		HashValue();
		HashValue(const K& k,const T& d);
		
		bool operator==(K& k) {return(key==k);}
		bool operator!=(K& k) {return(key!=k);}

		//���Ǹ�ɶ�ģ���ôǿ������ 
		operator T() const {return key;}
		
		//���˸�const,������ֵΪ0ʱ�㲻������� 
		HashValue<K,T>& operator=(const K& k)
		{
			key = k;
			return *this;
		}
		
		void Output(ostream& os) const;
	private:
		K key;
		T data;
};

template<class K,class T>
HashValue<K,T>::HashValue()
{
	key = 0;
	data = 0;
}

template<class K,class T>
HashValue<K,T>::HashValue(const K& k,const T& d)
{
	key = k;
	data = d;
}

template <class K,class T>
void HashValue<K,T>::Output(ostream &os) const
{
	os<<data<<endl;
}
template<class K,class T>
ostream& operator<<(ostream& os,const HashValue<K,T> &value)
{
	value.Output(os);
	return os;
}
#endif
