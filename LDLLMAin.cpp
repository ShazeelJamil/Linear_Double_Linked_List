#include"LDLL.h"
int main()
{
	LDLL<int> q;
	q.insertAtTail(0);
	q.insertAtTail(1);
	//q.insertAtTail(2);
	//q.insertAtTail(3);
	//q.insertAtTail(4);
	//q.insertAtTail(5);
	//q.insertAtTail(6);

	q.reverseList();
	q.display();
	return 0;
}