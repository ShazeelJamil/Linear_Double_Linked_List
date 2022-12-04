#include"LDLL.h"
template<typename T>
LDLL<T>::LDLL()
{
	head = nullptr;
}
template<typename T>
LDLL<T>::LDLL(const LDLL<T>& ref)
{
	*this = ref;
}
template<typename T>
LDLL<T>& LDLL<T>::operator=(const LDLL<T>& ref)
{
	if (!ref.head)
		return *this;
	Node<T>* temp = ref.head;
	while (temp)
	{
		insertAtTail(temp->info);
		temp = temp->nextPtr;
	}
	return *this;
}
template<typename T>
void LDLL<T>::insertAtHead(const T& val)
{
	Node<T>* newNode = new Node<T>(val);
	newNode->nextPtr = head;
	head = newNode;
	newNode->prevPtr = nullptr;
}
template<typename T>
void LDLL<T>::insertAtTail(const T& val)
{
	if (!head)
	{
		insertAtHead(val);
		return;
	}
	Node<T>* temp = head;
	while (temp->nextPtr != nullptr)
		temp = temp->nextPtr;
	Node<T>* newNode = new Node<T>(val);
	newNode->nextPtr = nullptr;
	newNode->prevPtr = temp;
	temp->nextPtr = newNode;
}
template<typename T>
void LDLL<T>::insertBefore(const T& key, const T& val)
{
	if (!head)
		return;
	if (head->info == key);
	{
		insertAtHead(val);
		return;
	}
	Node<T>* pre = head;
	Node<T>* temp = head->nextPtr;
	while (temp != nullptr)
	{
		if (temp->info == key)
		{
			cout << temp->info << '\n';
			Node<T>* newNode = new Node<T>(val);
			newNode->nextPtr = pre->nextPtr;
			newNode->prevPtr = temp->prevPtr;
			pre->nextPtr = newNode;
			temp->prevPtr = newNode;
			return;
		}
		pre = temp;
		temp = temp->nextPtr;
	}
}
template<typename T>
void LDLL<T>::insertAfter(const T& key, const T& val)
{
	if (!head)
		return;
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		if (temp->info == key)
		{
			if (temp->nextPtr == nullptr)
			{
				insertAtTail(val);
				return;
			}
			Node<T>* nextNode = temp->nextPtr;
			Node<T>* newNode = new Node<T>(val);
			newNode->nextPtr = nextNode;
			nextNode->prevPtr = newNode;
			newNode->prevPtr = temp;
			temp->nextPtr = newNode;
			return;
		}
		temp = temp->nextPtr;
	}
}
template<typename T>
void LDLL<T>::deleteAtHead()
{
	if (!head)
		return;
	if (!(head->nextPtr))
	{
		delete head;
		head = nullptr;
		return;
	}
	Node<T>* temp = head;
	head = head->nextPtr;
	head->prevPtr = nullptr;
	temp->nextPtr = nullptr;
	delete temp;	
}
template<typename T>
void LDLL<T>::deleteAtTail()
{
	if (!head)
		return;
	if (!head->nextPtr)
	{
		deleteAtHead();
		return;
	}
	Node<T>* pre = head;
	Node<T>* temp = head->nextPtr;
	while (temp->nextPtr != nullptr)
	{
		pre = temp;
		temp = temp->nextPtr;
	}
	temp->prevPtr = nullptr;
	delete temp;
	pre->nextPtr = nullptr;
}
template<typename T>
void LDLL<T>::deleteBefore(const T& key)
{
	if (!head || head->info == key)
		return;
	if (head->nextPtr->info == key)
	{
		deleteAtHead();
		return;
	}
	Node<T>* pre = head;
	Node<T>* temp = head->nextPtr;
	while (temp->nextPtr != nullptr)
	{
		if (temp->nextPtr->info == key)
		{
			temp = temp->nextPtr;
			temp->prevPtr = pre;
			pre->nextPtr->nextPtr = nullptr;
			pre->nextPtr->prevPtr = nullptr;
			delete pre->nextPtr;
			pre->nextPtr = temp;
			return;
		}
		pre = temp;
		temp = temp->nextPtr;
	}
}
template<typename T>
void LDLL<T>::deleteAfter(const T& key)
{
	if (!head)
		return;
	Node<T>* temp = head;
	while (temp->nextPtr != nullptr)
	{
		if (temp->info == key)
		{
			if (temp->nextPtr->nextPtr == nullptr)
			{
				deleteAtTail();
				return;
			}
			Node<T>* nextNode = temp->nextPtr->nextPtr;
			nextNode->prevPtr = temp;
			temp->nextPtr->nextPtr = nullptr;
			temp->nextPtr->prevPtr = nullptr;
			delete temp->nextPtr;
			temp->nextPtr = nextNode;
			return;
		}
		temp = temp->nextPtr;
	}
}
template<typename T>
void LDLL<T>::printPairsOf(const T& key)
{
	if (!head || head->info == key)
		return;
	Node<T>* headPtr = head;
	Node<T>* tailPtr = head;
	while (tailPtr->info < key)
		tailPtr = tailPtr->nextPtr;
	while (headPtr != tailPtr->nextPtr)
	{
		if (headPtr->info + headPtr->info == key)
		{
			cout << "(" << headPtr->info << " , " << headPtr->info << ") ";
			return;
		}
		else if (tailPtr->info + tailPtr->info == key)
		{
			cout << "(" << tailPtr->info << " , " << tailPtr->info << ") ";
			return;
		}
		else if (headPtr->info + tailPtr->info == key)
		{
			cout << "(" << headPtr->info << " , " << tailPtr->info << ") ";
			headPtr = headPtr->nextPtr;
			tailPtr = tailPtr->prevPtr;
		}
		else
		{
			if (headPtr->info + tailPtr->info < key)
				headPtr = headPtr->nextPtr;
			tailPtr = tailPtr->prevPtr;
		}
	}
}
template<typename T>
void LDLL<T>::reverseList()
{
	if (!head || !head->nextPtr)
		return;
	static int len = getLengthOfLL() - 1;
	if (len == 0)
	{
		deleteAtHead();
		return;
	}
	Node<T>* prev = head;
	Node<T>* ptr = head;
	int count = 1;
	while (count < len)
	{
		prev = ptr;
		ptr = ptr->nextPtr;
		count++;
	}
	insertAtTail(ptr->info);
	prev->nextPtr = ptr->nextPtr;
	prev->nextPtr->prevPtr = prev;
	len--;
	reverseList();
}
template<typename T>
int LDLL<T>::getLengthOfLL()
{
	if (!head)
		return 0;
	Node<T>* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		temp = temp->nextPtr;
		i++;
	}
	return i;
}
template<typename T>
LDLL<T>::~LDLL()
{
	delete head;
	head = nullptr;
}
template<typename T>
void LDLL<T>::display()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->info << " ";
		temp = temp->nextPtr;
	}
	cout << '\n';
}