//insuffcient memory
#ifndef XCEPT_H_
#define XCEPT_H_

#include <new>
//������new 
using namespace std;
class NoMem
{
	public:
		NoMem(){}
};//���Ų�Ҫ�� 

//change new to throw NoMem instead of xallorc
void my_new_handler()
{
	throw NoMem();
}

new_handler Old_Handler_ = set_new_handler(my_new_handler);

class OutOfBounds {
	public:
	OutOfBounds() {}
};
#endif
