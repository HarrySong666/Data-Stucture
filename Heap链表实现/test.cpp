#include <iostream>
#include <cstring>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "HeapNode.h"

using namespace std;

/*The answer is "you don't want to implement heap sort on a linked list."

Heapsort is a good sorting algorithm because it's O(n log n) and it's in-place.
However, when you have a linked list heapsort is no longer O(n log n) because it relies on random access to the array, 
which you do not have in a linked list. 

So you either lose your in-place attribute (but needing to define a tree-like structure is O(n) space). 
Or you will need to do without them, but remember that a linked list is O(n) for member lookup. 
Which brings the runtime complexity to something like  O(n^2 log n) which is worse than bubblesort.

Just use mergesort instead. You already have the O(n) memory overhead requirement.

*/
int main()
{
	MinHeap<int> heap; 

	while(true)
	{
		cout<<"��ѡ��Ҫ���еĲ���"<<endl;
		cout<<"0.�˳�  1.����Ԫ��  2.ɾ��Ԫ��  3.��ʼ��  4.������"<<endl;
		
		int choice;
		cin>>choice;
		if(choice==1)
		{
			cout<<"����������Ҫ�����Ԫ�ص�ֵ:";
			int num;
			cin>>num;
			
			heap.Insert(num);
			cout<<"�����������"<<endl;
			heap.Print();
		}else if(choice==2)
		{
			cout<<"ɾ����Ԫ�ص�ֵΪ:"<<heap.Delete()<<endl;
			cout<<"ɾ��Ԫ�غ�ѵ�Ԫ������ͼ��ʾ"<<endl;
			heap.Print();
		}else if(choice==3)
		{
			cout<<"����������Ҫ�����Ķѵ�Ԫ�ظ���:";
			int n;
			cin>>n;
			
			int input[n];
			cout<<"����������Ҫ�����Ķѵ�Ԫ��"<<endl;
			for(int i=0;i<n;i++)
			{
				cin>>input[i];
			}
			heap.Initialize(input,n);
			cout<<"������������ͼ��ʾ"<<endl;
			heap.Print();
		}else if(choice==4)
		{
			cout<<"��ѡ������ʽ��0.��С����   1.�Ӵ�С"<<endl;
			int q;
			cin>>q;
			if(q)
			{
				MaxHeap<int> temp;
				cout<<"����������Ҫ�����Ԫ�صĸ���:"<<endl;
				int n;
				cin>>n;
				
				int input[n];
				cout<<"����������Ҫ�����Ķѵ�Ԫ��"<<endl;
				for(int i=0;i<n;i++)
				{
					cin>>input[i];
				}
				temp.Initialize(input,n);
				
				cout<<"���ý������"<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<temp.Delete()<<" ";
				}
				cout<<endl;
			}else
			{
				MinHeap<int> temp;
				cout<<"����������Ҫ�����Ԫ�صĸ���:"<<endl;
				int n;
				cin>>n;
				
				int input[n];
				cout<<"����������Ҫ�����Ķѵ�Ԫ��"<<endl;
				for(int i=0;i<n;i++)
				{
					cin>>input[i];
				}
				temp.Initialize(input,n);
				cout<<"���ý������"<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<temp.Delete()<<" ";
				}
				cout<<endl;
			}
		}else if(choice==0)
		{
			break;
		}else
		{
			cout<<"����Ƿ�"<<endl;
		}
	}
}
