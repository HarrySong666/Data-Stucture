#include <iostream>
#include <cstring>
#include <string>
#include "HashTable.h"
#include "HashValue.h"
using namespace std;

/*��δ��ɵĵط�
1.HashTable����Щ�׳��쳣��δ���,����˵ʧ�������û��˵��
2.HashValue����ĸ�ֵ���㻹û�㶮
3.string��char�����ת�� 
4.����������ţ����ǿ��,���˸�const�ͺ��� 
*/
int main()
{
//	string str = "Hi";
//	HashValue<int,string> a = new HashValue<int,string>(80,str);

	HashTable<int,HashValue<int,char> > table(11);
	HashValue<int,char> *a = new HashValue<int,char>(40,'a');
	HashValue<int,char> *b = new HashValue<int,char>(80,'b');
	HashValue<int,char> *c = new HashValue<int,char>(24,'c');
	HashValue<int,char> *d = new HashValue<int,char>(58,'d');
	HashValue<int,char> *e = new HashValue<int,char>(35,'e');
	
	table.Insert(*a);
	table.Insert(*b);
	table.Insert(*c);
	table.Insert(*d);
	table.Insert(*e);
	
	HashValue<int,char> temp;
	table.Search(58,temp);
	table.Delete(58,temp);
	
	cout<<table.Pos(35);
	
}
