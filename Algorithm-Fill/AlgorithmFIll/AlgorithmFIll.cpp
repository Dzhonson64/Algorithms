// AlgorithmFIll.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void fillStack(char ** area, int lenX, int lenY, int i, int j, char color1, char color2);
void printArray(char ** str);

/*Version 2*/
struct NodeStack {				
	NodeStack * head = NULL;	 	
	NodeStack * pDown = NULL;		
	int x;
	int y;
	char data;
	int size;
} Stack;
void push( int x, int y);			
void pop();
void show();					
NodeStack * top();
int empty();



/*struct QueueNode {
	QueueNode * head = NULL;
	QueueNode * pNext = NULL;
	int x;
	int y;
	int size = 0;
} newQueueNode;
void pushQ(int i, int j);
void popQ();
void showQ();
QueueNode * topQ();
int emptyQ();
void fillQueue(char **area, int lenX, int lenY, int i, int j);*/

const int sizeArr = 6;
int main()
{
	fstream fs;
	char ** str = new char*[sizeArr];
	for (int i = 0; i < sizeArr; i++) {
		str[i] = new char[sizeArr];
	}
	fs.open("area.txt", ios::in | ios::out);
	if (fs.is_open()) {
		int i = 0;
		while (i < sizeArr) {
			int j = 0;
			while (j < sizeArr) {
				fs >> str[i][j];
				j++;
			}
			i++;
		}

			printArray(str);
			fillStack(str, sizeArr, sizeArr, 2, 2, '0', '2');
			std::cout << endl;
			printArray(str);
	}
	else {
		std::cout << "Error" << endl;
	}
}





void push(int x, int y) {
	struct NodeStack * node = &Stack;
	if (node->head == NULL) {			
		node->head = new NodeStack;
		//node->head->data = item;
		node->head->x = x;
		node->head->y = y;
	}
	else {						
		NodeStack * temp = node->head;
		node->head = new NodeStack;
		//node->head->data = item;
		node->head->x = x;
		node->head->y = y;
		node->head->pDown = temp;
		
	}
}

void pop()
{
	struct NodeStack * node = &Stack;
	NodeStack * temp = node->head;			
	char oldBracket = node->head->data;
	node->head = node->head->pDown;			
	delete temp;
}

void show()
{
	struct NodeStack * node = &Stack;
	NodeStack * temp = node->head;
	while (temp != NULL) {			
		std::cout << temp->x << ", " << temp->y << "\t";
		temp = temp->pDown;
	}
}
NodeStack * top() {
	struct NodeStack * node = &Stack;
	if (node->head != NULL) {
		return node->head;
	}
	return NULL;

}
int empty() {
	struct NodeStack * node = &Stack;
	if (node->head != NULL) {
		return 0;
	}
	else {
		return 1;
	}
}








void fillStack(char ** area, int lenX, int lenY, int i, int j, char color1, char color2)
{
	//color1 - что меняем
	//color2 - на что меняем
	struct NodeStack * node = &Stack;
	push(i, j);
	int x = 0;
	int y = 0;
	if (area[j][i] == color1) {
		area[j][i] = color2;
	}
	
	while (!empty()) {
		x = top()->x;
		y = top()->y;
		cout << "X - " << x << "\nY - " << y << endl;
		pop();
		if (x + 1 < lenX  && area[y][x + 1] == color1) { // восток
			area[y][x + 1] = color2;
			push(x + 1, y);
		}
		if (x - 1 >= 0 && area[y][x - 1] == color1) {// запад
			area[y][x - 1] = color2;
			push(x - 1, y);
		}
		if (y - 1 >= 0 && area[y - 1][x] == color1) { // юг
			area[y - 1][x] = color2;
			push(x, y - 1);
		}
		if (y + 1 < lenY  && area[y + 1][x] == color1) { // север
			area[y + 1][x] = color2;
			push(x, y + 1);
		}
		cout << endl;
		show();
		cout << endl;
		printArray(area);


		/*if (y - 1 > 0 && x - 1 > 0 && area[y - 1][x - 1] == '0') { //северо-запад
			area[y - 1][x + 1] = '1';
			push(y + 1, x + 1);
			std::cout << "y + 1 = " << y + 1 << endl;
			std::cout << "x - 1 = " << x - 1 << endl;
		}
		if (y - 1 > 0 && x + 1 < lenX && area[y - 1][x + 1] == '0') { //северо-восток
			area[y - 1][x + 1] = '1';
			push(y - 1, x + 1);
			std::cout << "y - 1 = " << y - 1 << endl;
			std::cout << "x + 1 = " << x + 1 << endl;
		}
		if (y + 1 < lenY && x - 1 > 0 && area[y + 1][x - 1] == '0') { //юго-запад
			area[y + 1][x - 1] = '1';
			push(y + 1, x - 1);
			std::cout << "y + 1 = " << y + 1 << endl;
			std::cout << "x - 1 = " << x - 1 << endl;
		}
		if (y + 1 < lenY && x + 1 < lenX && area[y + 1][x + 1] == '0') { //юго-восток
			area[y + 1][x - 1] = '1';
			push(y + 1, x - 1);
			std::cout << "y + 1 = " << y + 1 << endl;
			std::cout << "x + 1 = " << x + 1 << endl;
		}*/
	}
}







/*void pushQ(int i, int j) {
	struct QueueNode * node = &newQueueNode;
	if (node->head == NULL) {
		node->head = new QueueNode;
		node->head->x = i;
		node->head->y = j;
	}
	else {
		QueueNode * current = node->head;
		while (current->pNext != NULL) {
			current = current->pNext;
		}
		current->pNext = new QueueNode;
		current->pNext->x = i;
		current->pNext->y = j;
	}
	node->size++;
}
void popQ() {
	struct QueueNode * node = &newQueueNode;
	QueueNode * current = node->head;
	QueueNode * temp = node->head;
	node->head = node->head->pNext;
	node->size--;
	delete temp;
}
void showQ() {
	struct QueueNode * node = &newQueueNode;
	QueueNode * current = node->head;
	while (current != NULL) {
		cout << current->x << ";" << current->y << "\t";
		current = current->pNext;
	}
}
QueueNode * topQ() {
	struct QueueNode * node = &newQueueNode;
	return node->head;
}
int emptyQ() {
	struct QueueNode * node = &newQueueNode;
	if (node->head != NULL) {
		return 0;
	}
	else {
		return 1;
	}
}
void fillQueue(char ** area, int lenX, int lenY, int i, int j)
{
	struct QueueNode * node = &newQueueNode;
	pushQ(i, j);
	int x = 0;
	int y = 0;
	area[j][i] = '1';
	while (!emptyQ()) {
		x = topQ()->x;
		y = topQ()->y;
		cout << endl;
		cout << "X - " << x << endl;
		cout << "Y - " << y << endl;
		popQ();
		if (x + 1 < lenX && area[y][x + 1] == '0') { // восток
			area[y][x + 1] = '1';
			pushQ(x + 1,  y);
			std::cout << "x + 1 = " << x + 1 << "; " << y << endl;
		}
		if (x - 1 >= 0 && area[y][x - 1] == '0') {// запад
			area[y][x - 1] = '1';
			pushQ(x - 1, y);
			std::cout << "x - 1 = " << x - 1 << "; " << y << endl;
		}
		if (y - 1 >= 0 && area[y - 1][x] == '0') { // юг
			area[y - 1][x] = '1';
			pushQ(x, y - 1);
			std::cout << x << "; y - 1 = " << y - 1 << endl;
		}
		if (y + 1 < lenY && area[y + 1][x] == '0') { // север
			area[y + 1][x] = '1';
			pushQ(x, y + 1);
			std::cout << x << "; y + 1 = " << y + 1 << endl;
		}

		std::cout << endl;
		printArray(area);
		std::cout << "\tQueue: ";
		showQ();
	}
	
}*/
void printArray(char ** str) {
	for (int i = 0; i < sizeArr; i++) {
		for (int j = 0; j < sizeArr; j++) {
			cout << str[i][j];
		}
		cout << endl;
	}
}




