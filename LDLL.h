#ifndef LDLL_H
#define LDLL_H
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class LDLL
{
	Node<T>* head;
	int getLengthOfLL();
public:
	LDLL();
	LDLL(const LDLL<T>& ref);
	LDLL<T>& operator=(const LDLL<T>& ref);
	void insertAtHead(const T& val);
	void insertAtTail(const T& val);
	void insertBefore(const T& key, const T& val);
	void insertAfter(const T& key, const T& val);
	void deleteAtHead();
	void deleteAtTail();
	void deleteBefore(const T& key);
	void deleteAfter(const T& key);
	void printPairsOf(const T& key);
	void reverseList();
	void display();
	~LDLL();

	
};
#endif // !LDLL_H
