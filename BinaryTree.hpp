#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>

class BinaryTree{
private:
	Node<T>* root;

	Node<T>* deleteRecursive(Node<T>* current, T value){
		if(current==nullptr) return nullptr;

		if(current->data==value){
			if(current->left==nullptr && current->right==nullptr){
				delete current;
				return nullptr;
			}
			if(current->left==nullptr){
				Node<T>* temp= current->right;
				delete current;
				return temp;
			}
			if(current->right==nullptr){
				Node<T>* temp=current->left;
				delete current;
				return temp;
			}

			Node<T>* successor=findMin(current->right);
			current->data=successor->data;
			current->right=deleteRecursive(current->right, successor->data);
		}else{
			current->left=deleteRecursive(current->left, value);
			current->right=deleteRecursive(current->right, value);
		}
		return current;
	}

	Node<T>* findMin(Node<T>* node){
		while(node->left!=nullptr) node=node->left;
		return node;
	}

	bool searchRecursive(Node<T>* current, T value){
		if(current==nullptr) return false;
		if(current->data==value) return true;
		return searchRecursive(current->left, value) || searchRecursive(current->right, value);
	}

	void inorderRecursive(Node<T>* node){
		if(node!=nullptr){
			inorderRecursive(node->left);
			std::cout<<node->data<<" "<<std::endl;
			inorderRecursive(node->right);
		}
	}

	void preOrderRecursive(Node<T>* node){
		if(node!=nullptr){
			std::cout<<node->data<<" "<<std::endl;
			preOrderRecursive(node->left);
			preOrderRecursive(node->right);
		}
	}

	void postOrderRecursive(Node<T>* node){
		if(node!=nullptr){
			postOrderRecursive(node->left);
			postOrderRecursive(node->right);
			std::cout<<node->data<<" "<<std::endl;
		}
	}

	void getNodes(Node<T>* node, std::vector<Node<T>*>& nodes){
		if(node!=nullptr){
			getNodes(node->left,nodes);
			nodes.push_back(node);
			getNodes(node->right,nodes);
		}
	}

public:
	BinaryTree(): root(nullptr) {}

	void insertNode(T value){
		Node<T>* newNode=new Node<T>(value);

		if(root==nullptr){
			root=newNode;
			return;
		}

		std::queue<Node<T>*> q;
		q.push(root);

		while(!q.empty()){
			Node<T>* current=q.front();
			q.pop();
			if(current->left==nullptr){
				current->left=newNode;
				return;
			}else{
				q.push(current->left);
			}

			if(current->right==nullptr){
				current->right=newNode;
				return;
			}else{
				q.push(current->right);
			}
		}
	}

	void deleteNote(T value){
		root=deleteRecursive(root, value);
	}

	void search(T value){
		root=searchRecursive(root, value);
	}

	void inorder(){
		inorderRecursive(root);
		std::cout<<std::endl; 
	}

	void preorder(){
		preOrderRecursive(root);
		std::cout<<std::endl;
	}

	void postorder(){
		postOrderRecursive(root);
		std::cout<<std::endl;
	}

	void leveOrder(){
		if(root==nullptr) return;

		std::queue<Node<T>*> q;
		q.push(root);

		while(!q.empty()){
			Node<T>* current=q.front();
			q.pop();

			std::cout<<current->data<<std::endl;

			if(current->left!=nullptr) q.push(current->left);
			if(current->right!=nullptr) q.push(current->right);
		}
		std::cout<<std::endl;
	}

	std::vector<Node<T>*> getNodes(){
		std::vector<Node<T>*> nodes;
		getNodes(root, nodes);
		return nodes;
	}

    //con esto se supone que se hace accesible lo privado
	Node<T>* getRoot() const{
		return root;
	}

	bool isEmpty() const{
		return root==nullptr;
	}
};

#endif // BINARYTREE_H