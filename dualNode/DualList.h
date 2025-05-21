#pragma once

#include <iostream>

class Node { //����
	std::unique_ptr<int>data; //����� ��� ������
	std::shared_ptr<Node>next; //����� ��� ������ ���������� ��������
public:

	Node(int value);

	~Node();

	Node& setData(int value);

	Node& setNext(std::shared_ptr<Node>next);

	int& getData();

	std::shared_ptr<Node>& getNext();
};

class List { // ����
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
�������� �������� �� �������
�������� ������ �����
*/