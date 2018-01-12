#include <iostream>
#include <cstring>
#include <string>
#include "BST.h"
#include "Value.h"
#include "TreeNode.h"

using namespace std;

/*��δ����ĵط�
1.ָ���һЩ���⡣current = 0�Ƿ���С� �� 
2.����BST��TreeNode����Ԫ���⡣ 
3.ʱ�临�Ӷȷ��� 
*/

int main()
{
	Value<int,char> value1(19,'e');
	Value<int,char> value2(10,'b');
	Value<int,char> value3(15,'a');
	Value<int,char> value4(20,'f');
	Value<int,char> value5(12,'d');
	Value<int,char> value6(8,'c');
	
	BST<int,Value<int,char> > bst;
	
	bst.Insert(value1);
	bst.Insert(value2);
	bst.Insert(value3);
	bst.Insert(value4);
	bst.Insert(value5);
	bst.Insert(value6);
	
	Value<int,char> temp;
	bst.Delete(19,temp);
	Value<int,char> temp2(18,'q');
	bst.Insert(temp2);
	bst.Print();
}
