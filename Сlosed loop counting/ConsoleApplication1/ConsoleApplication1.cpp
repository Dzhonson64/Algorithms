// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Cut.h"
#include <iostream>

using namespace std;
int main()
{
	const int M = 10;
	const int N = 10;
	Cut * c = new Cut(M, N);
	c->addPos(0,9);
	c->addPos(1,8);
	c->addPos(2,7);
	c->addPos(3,6);
	c->addPos(3,5);
	c->addPos(4,5);
	c->addPos(5,6);
	c->addPos(5,7);
	c->addPos(6,8);
	c->addPos(7,8);
	c->addPos(8,8);
	c->addPos(9,8);
	c->addPos(4,3);
	c->addPos(4,2);
	c->addPos(4,1);
	c->addPos(4,0);
	c->addPos(4, 4);
	c->addPos(0, 6);
	c->addPos(1, 6);
	c->addPos(2, 6);
	c->addPos(0, 8);
	c->showArea();
	cout << "Count -  " << c->fillAndCount() << endl;
	c->showArea();
	delete c;
}