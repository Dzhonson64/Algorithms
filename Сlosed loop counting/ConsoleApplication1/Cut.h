#pragma once
#include <iostream>
using namespace std;

class Cut
{
private:
	int count = 0; // кол-во вырезанных кусков
	int M;
	int N;
	int ** area; // массив хранение поля (1 - это невырезанная часть, а 0 - вырезанная часть, а 2 - проверенная часть)
	int fill(int x, int y); // заполнение области
public:
	Cut();
	Cut(int M, int N);
	~Cut();
	
	void addPos(int x, int y); // добавление позиции с координатами
	int fillAndCount(); // поиск куска и подсчёт кусков
	void showArea(); // вывод поля на экран
};

