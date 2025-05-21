#include "DualList.h"

Node::Node(int value) : data{ std::make_unique<int>(value) }, next{ nullptr } { std::cout << "n" << value << " created\n"; }

Node::~Node() { std::cout << "n" << *data << " destroyed\n"; }

Node& Node::setData(int value) { *data = value; return *this; }

Node& Node::setNext(std::shared_ptr<Node>next) { this->next = next; return *this; }

int& Node::getData() { if (data)return *data; else throw std::exception("data is empty"); }

std::shared_ptr<Node>& Node::getNext() { return next; }

List::List() : first{ nullptr }, last{ nullptr }, size{ 0 } {};

List& List::addNode(int value) {
	if (!first) {
		first = last = std::make_shared<Node>(value);
		size++;
	}
	else {
		last->setNext(std::make_shared<Node>(value));
		last = last->getNext();
		size++;
	}
	return *this;
}

unsigned int List::getSize() const {
	return size;
}

List& List::removeNode(int index) {
	if (!first) std::cout << "List is empty";
	return *this;
}

int& List::operator[](int index) {
	if (first) {
		std::shared_ptr<Node>temp = first;
		for (int i = 0; i < index; i++) {
			if (temp) temp = temp->getNext();
			else throw std::out_of_range("Э, ты куда?\n");
		}
		return temp->getData();
	}
	else throw std::out_of_range("Э, ты куда?\n");
}

std::ostream& operator<<(std::ostream& out, const List& list) {
	std::shared_ptr<Node>temp = list.first;
	while (temp)
		if (temp) {
			out << temp->getData() << " ";
			temp = temp->getNext();
		}
		else throw std::out_of_range("Э, ты куда?\n");
	return out;
}