#include <iostream>
#include <cstring>
#include <string>
#include "MaxHBLT.h"
#include "HBLTNode.h"

using namespace std;
/*Ŀǰ���ڵ�����
1.����������û����� 
2.��һ�����ʣ�Ϊʲô��������MaxHBLTʱ��leftChild���ᱨ�������������򣬾ͻ�˵leftChild������(ʵ��Ϊleft) ��(Դ�ļ�δ����...) 
3.-> �� . ������ʲô����  �� 
4.���������Ķ��� 
5.ѧϰ�����÷� 
6.ʱ�临�Ӷȷ��� 
*/
int main()
{
	MaxHBLT<int> A;
	MaxHBLT<int> B;
	int a[3] = {18,7,6};
	int b[5] = {40,30,5,20,10};
	A.Initialize(a,3);
	B.Initialize(b,5);
//	A.Meld(B);
	
	A.Print();
	B.Print();
}
