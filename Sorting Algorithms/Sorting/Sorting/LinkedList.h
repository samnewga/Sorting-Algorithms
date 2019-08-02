#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"


// Template with type name T and LinkedList class
template<typename T>
class LinkedList
{

	// Public variables, constructor and deconstructor
public:
	LinkedList();

	~LinkedList();

	Node<T>* get_head();

	Node<T>* get_tail();

	long get_size();

	void insert(T data);

	Node<T>* find(T data_find);

	void remove(T data_delete);

	Node<T>* maximum();

	Node<T>* minimum();

	// Private variables, head and tail
private:
	Node<T>* head;
	Node<T>* tail;
	long size;

};

// Sets the head and tail to null pointer at start
template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// Deconstructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* current = tail;

	while (current != head)
	{
		current = current->get_prev();
		delete current->get_next();
	}
	delete current;
}

// Get head is set to return head
template <typename T>
Node<T>* LinkedList<T>::get_head()
{
	return head;
}

// Get tail is set to return tail
template <typename T>
Node<T>* LinkedList<T>::get_tail()
{
	return tail;
}

// Insert function definition, if head is null pointer set it to the new node, after head is no longer null set tail to new node
template <typename T>
void LinkedList<T>::insert(T data)
{
	Node<T>* new_node = new Node<T>(data);
	if (head == nullptr)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->set_next(new_node);
		new_node->set_prev(tail);
		tail = new_node;
	}
	size++;
}

// Find function definition, if the list is not null , get data from list
template <typename T>
Node<T>* LinkedList<T>::find(T data_find)
{
	Node<T>* list_cycle = head;

	while (list_cycle != nullptr && list_cycle->get_data() != data_find)
	{
		list_cycle = list_cycle->get_next();
	}
	return list_cycle;
}

// Remove function definition
template <typename T>
void LinkedList<T>::remove(T data_delete)
{
	Node<T>* node_delete = find(data_delete);
	if (node_delete == nullptr)
	{
		return;
	}
	else if (node_delete == head && node_delete == tail)
	{
		head = nullptr;
		tail = nullptr;
		delete node_delete;
	}
	else if (node_delete == head)
	{
		head = head->get_next();
		head->set_prev(nullptr);
		node_delete->set_next(nullptr);
		delete node_delete;
	}
	else if (node_delete == tail)
	{
		tail = tail->get_prev();
		tail->set_next(nullptr);
		node_delete->set_prev(nullptr);
		delete node_delete;
	}
	else
	{
		Node<T>* next_node = node_delete->get_next();
		Node<T>* prev_node = node_delete->get_prev();
		prev_node->set_next(node_delete->get_next());
		next_node->set_prev(node_delete->get_prev());
		delete node_delete;
	}
}

// Checks the maximum value in the linkedlist
template <typename T>
Node<T>* LinkedList<T>::maximum()
{
	Node<T>* current = head;
	Node<T>* max_node = head;
	while (current != nullptr)
	{
		if (current->get_data() > max_node->get_data())
		{
			max_node = current;
		}
		current = current->get_next();
	}
	return max_node;
}

// Checks the minimum value in the linkedlist
template <typename T>
Node<T>* LinkedList<T>::minimum()
{
	return nullptr;
}

// Get's the size of the linked list
template <typename T>
long LinkedList<T>::get_size()
{
	return size;
}

#endif
