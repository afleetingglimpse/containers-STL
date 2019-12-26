#include<iostream>
#include <Windows.h>
using namespace std;

template<typename T>
class queue
{
private:
	template<typename T>
	class Node
	{
	public:
		T Data;
		Node<T>* next;
		Node(T data = T(), Node* next = nullptr)
		{
			Data = data;
			this->next = next;
		}
	};
	Node<T> *begin;
	int size;
public:
	queue();
	~queue();
	void add(T value);	
	void fetch();
	void pop();
	int getSize();
	bool empty();
};

template<typename T>
queue<T>::queue()
{
	size = 0;
	begin = nullptr;
}

template<typename T>
queue<T>::~queue()
{
	while (size)
		pop();
}

template<typename T>
void queue<T>::add(T value)
{
	if (begin == nullptr)
	{
		begin = new Node<T>(value);
	}
	else
	{
		Node<T>* current = this->begin;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		Node<T>* newNode = new Node<T>(value, current->next);
		current->next = newNode;
	}
	size++;
}

template<typename T>
void queue<T>::fetch()
{
	Node<T>* current = begin;
	cout << current->Data<<endl;
	pop();
}

template<typename T>
void queue<T>::pop()
{
	Node<T>* temp = begin;
	begin = begin->next;
	delete temp;
	size--;
}

template<typename T>
int queue<T>::getSize()
{
	return size;
}

template<typename T>
bool queue<T>::empty()
{
	if (size > 0)
		return false;
	else
		return true;
}

int main()
{
	queue<int> a;
	a.add(3);
	a.add(4);
	a.add(5);
	a.add(6);
	a.add(7);
	a.add(10);

	while (int i = a.getSize() > 3)
	{
		a.fetch();
		Sleep(1000);
	}
	if (a.empty())
		cout << "Queue is empty now" << endl;
	else
		cout << "Queue is still not empty" << endl;
}