#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node
{
	T info;
	Node<T>* prevPtr;
	Node<T>* nextPtr;
	Node()
	{
		prevPtr = nullptr;
		nextPtr = nullptr;
	}
	Node(T val)
	{
		info = val;
		nextPtr = nullptr;
		prevPtr = nullptr;
	}
	/*~Node()
	{
		delete nextPtr;
		nextPtr = nullptr;
		prevPtr = nullptr;
	}*/
};

#endif // !
