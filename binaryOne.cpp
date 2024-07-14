#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <vector>
#include "Node.h"
#include "BinaryTree.hpp"

int main(){

	sf::RenderWindow window(sf::VideoMode(1000,800),"BinaryTree");

	//el CircleShape jamas acepta como argumento un sf::Vector2f, los demas si pero este no

	sf::CircleShape Circle(15.0f);
	Circle.setFillColor(sf::Color::Blue);

	BinaryTree<int> tree;
	tree.insertNode(1);
	tree.insertNode(2);
	tree.insertNode(3);
	tree.insertNode(5);
	tree.insertNode(6);
	tree.insertNode(7);
	tree.insertNode(8);

	std::vector<Node<int>*> nodes=tree.getNodes();

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				window.close();
			}
		}
		window.clear();

		//logic here...
		float x=100.0f;
		float y=100.0f;
		float y_offset=100.0f;
		for(auto node: nodes){
			Circle.setPosition(x,y);
			window.draw(Circle);
			x += y_offset;
		}

		window.display();
	}

	return 0;
}