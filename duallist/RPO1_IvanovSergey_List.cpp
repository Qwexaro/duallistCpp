#include <iostream>

class Node { //Узел
	std::unique_ptr<int>data; //Место под данные
	std::shared_ptr<Node>next; //Место под адресс следующего элемента
public:

	Node(int value) : data{ std::make_unique<int>(value) }, next{ nullptr } { std::cout << "n" << value << " created\n"; }
	
	~Node() { std::cout << "n" << *data << " destroyed\n"; }
	
	void setData(int value) { *data = value; }
	
	void setNext(std::shared_ptr<Node>next) { this->next = next; }
	
	int& getData() { if (data)return *data; else throw std::exception("data is empty"); }
	
	std::shared_ptr<Node>& getNext() { return next; }
};

class List { // Лист
	std::shared_ptr<Node>first, last;
public:
	List() : first{ nullptr }, last{ nullptr } {};
	
	List& addNode(int value) {
		if (!first) {
			first = last = std::make_shared<Node>(value);
		}
		else {
			last->setNext(std::make_shared<Node>(value));
			last = last->getNext();
		}
		return *this;
	}
	
	int& operator[](int index) {
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
	
	friend std::ostream& operator<<(std::ostream& out, const List& list) {
		std::shared_ptr<Node>temp = list.first;
		while(temp) 
			if (temp) {
				out << temp->getData() << " ";
				temp = temp->getNext();
			}
			else throw std::out_of_range("Э, ты куда?\n");
		return out;
	}
};

int main()
{
	system("chcp 1251");
	
	List l1;
	
	l1.addNode(-14).addNode(55).addNode(70).addNode(0);
	
	std::cout << l1 << std::endl;
	
	return 0;
}