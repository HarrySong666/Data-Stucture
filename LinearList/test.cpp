#include <iostream>
#include <cstdio>
#include "linearList.h"
#include "xcept.h"

int main()
{
	LinearList<int> L(5);
	cout<<"Length = "<<L.Length()<<endl;
	L.Insert(0,5);
	cout<<"Length = "<<L.Length()<<endl;
	L.Insert(1,5).Insert(2,3);
	//Insert���ڵ�iλ�������֣�����(1,n)�Ͳ��ǵ�һλ 
	cout<<"Length = "<<L.Length()<<endl;
	
	int z;
	L.Find();//һ��ʼд����Find(),����L. 
	//Find�������ҵ�i������ԭ��д��(0,n)�Ǿ��������-1�� 
	cout<<"First Element = "<<z<<endl;
	L.Delete(3,z);
	//Delete��Findһ����֮ǰ��ȫ������� 
	cout<<"Deleted element is "<<z<<endl;
	cout<<"Length = "<< L.Length()<<endl;
	cout<<"List is "<< L <<endl; 
	//ע��L������Ϊ0����������һ��û�У��������һ������ 
	
	return 0;
}
