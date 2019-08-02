#ifndef NODE_H
#define NODE_H

// Template for node class
template<typename T>
class Node
{

	// Public variables, constructor, deconstructor
public:
	Node();

	Node(T new_data);

	~Node();

	void set_data(T new_data);

	void set_next(Node* new_next);

	void set_prev(Node* new_prev);

	T get_data();

	Node* get_next();

	Node* get_prev();

	// Private variables, data, next and previous node
private:

	T data;
	Node* next_node;
	Node* prev_node;

};

// Sets data to null and next, prev node to null pointers at start
template <typename T>
Node<T>::Node()
{
	data = NULL;
	next_node = nullptr;
	prev_node = nullptr;
}

// Sets Node(T new_data) to new data and nodes to null pointers
template <typename T>
Node<T>::Node(T new_data)
{
	data = new_data;
	next_node = nullptr;
	prev_node = nullptr;
}

// Node deconstructor
template<typename T>
Node<T>::~Node() {}

template <typename T>

// Sets data to new data
void Node<T>::set_data(T new_data)
{
	data = new_data;
}

// Sets next node to new next
template <typename T>
void Node<T>::set_next(Node* new_next)
{
	next_node = new_next;
}

// Sets previous node to new previous
template <typename T>
void Node<T>::set_prev(Node* new_prev)
{
	prev_node = new_prev;
}

// Sets get data to return data
template <typename T>
T Node<T>::get_data()
{
	return data;
}

// Sets get next to return next node
template <typename T>
Node<T>* Node<T>::get_next()
{
	return next_node;
}

// Sets get previous to return previous node
template <typename T>
Node<T>* Node<T>::get_prev()
{
	return prev_node;
}

#endif