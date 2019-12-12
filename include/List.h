#pragma once
#include <iostream>

template <class T>
struct Node
{
	Node(const Node& copyNode);
	Node(T Data);
	T data;
	Node* next;
	Node* previous;
};

template <class T>
class List
{
public:
	List(const List& copyList);
	List() : begin(nullptr), end(nullptr), size(0) {}
	void push_back(T element);
	void pop_back();
	~List();
private:
	Node<T>* begin;
	Node<T>* end;
	int size;
};

template <class T>
Node<T>::Node(const Node& copyNode) : 
	data(copyNode.data), next(copyNode.next), previous(copyNode.previous) {}

template <class T>
Node<T>::Node(T Data) : data(Data), next(nullptr), previous(nullptr) {}

template <class T>
List<T>::List(const List& copyList) : 
	begin(copyList.begin), end(copyList.end), size(copyList.size)  {}

template<class T>
void List<T>::push_back(T element)
{
	if (begin == nullptr)
	{
		begin = new Node<T>(element);
		end = begin;
		size++;
	}
	else
	{
		Node<T>* temp = end;
		temp->next = new Node<T>(element);
		end = temp->next;
		temp->next->previous = temp;
		size++;
	}
}

template<class T>
void List<T>::pop_back()
{
	if (begin == nullptr)
		throw ("List is empty");
	else
	{
		Node<T>* temp = end;
		temp = temp->previous;
		temp->next = nullptr;
		end = temp;
		size--;
	}
}

template<class T>
List<T>::~List()
{
	if (begin == nullptr)
		return;
	Node<T>* temp = begin;
	while (temp->next != 0)
	{
		temp = temp->next;
		delete temp->previous;
		temp->previous->next = nullptr;
		temp->previous = nullptr;
	}
	temp->previous = nullptr;
	delete temp;
	end = nullptr;
	begin = nullptr;
}