#pragma once

#include <iostream>

class Node { //Узел
	std::unique_ptr<int>data; //Место под данные
	std::shared_ptr<Node>next; //Место под адресс следующего элемента
public:

	Node(int value);

	~Node();

	Node& setData(int value);

	Node& setNext(std::shared_ptr<Node>next);

	int& getData();

	std::shared_ptr<Node>& getNext();
};

class List { // Лист
	unsigned int size;
	std::shared_ptr<Node>first, last;
public:
	List();

	unsigned int getSize() const;

	List& addNode(int value);

	List& removeNode(int index);

	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const List& list);
};

/*
Удаление элемента по индексу
Очищение списка всего
*/