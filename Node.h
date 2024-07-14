#ifndef NODE_H
#define NODE_H

template <typename T> 

class Node{
public:
	T Data;
	Node* left;
	Node* right;

	Node(T value): Data(value), left(nullptr), right(nullptr) {}

};

#endif // NODE_H