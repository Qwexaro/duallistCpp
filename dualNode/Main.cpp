#include "DualList.h"

int main()
{
	system("chcp 1251");

	List l1;

	l1.addNode(-14).addNode(55).addNode(70).addNode(0).addNode(9).addNode(300);

	std::cout << "size:" << l1.getSize() << std::endl;

	std::cout << l1 << std::endl;

	return 0;
}