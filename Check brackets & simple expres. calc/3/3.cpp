// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
/*Task 1*/
using namespace std;
int Task1(string str);
int CharToInt(char c, int oldNum);// Перевод из char в int

/*Task 2*/
struct NodeStack {				 // структра узла Стека
	NodeStack * head = NULL;	 // указатель на голову Стека
	NodeStack * pDown = NULL;	 // уазатель на нижний элемент узла
	char brackets;
	int size;
} Stack;
void push(char bracket);	// добавление в Стек
char pop();					// удаление из Стек
void show();				// отображение на экран всего Стека
char top();					// возврат "головы" Стека
int Task2(string str);		/* Возвращает 0 - скобки находятся в балансе, и они правильно расположены;
								-1 - это скобки не находятся в балансе, или они не правильно расположены;*/
int main()
{
	string str = "100+9+100+100-17";
	cout << Task1(str) << endl;

	string str1 = "dgsgsgdsfdfdf";	
	cout << Task2(str1) << endl;
}
int Task1(string str) {
	int oldNum1 = 0;
	int operands[2];	// массив чисел
	char operators[1];  // массив арифм. знаков
	int result = 0;
	int j = 0;			// счётчик для массива operands[];
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {					  // если встретилась символьная цифра, то переводим её в int число
			oldNum1 = CharToInt(str[i], oldNum1);
		}
		if (str[i] == '+' || str[i] == '-' || str[i+1] == '\0') { // если встретили арифм. знак или конец строки, то выполняем арифм. дейстивие или добавления знака
			operands[j++] = oldNum1;							  // запоминаем левое или правое число, относительное арифм. знака

			if (operators[0] == '+') {							/* если в массиве есть + , то выполним сложение, при котором результат запишется в начало массива,
																	а первую ячейку обнуяем, для того, чтобы получить потом положить следующее число */
				result = operands[0] + operands[1];
				operands[0] = result;
				operands[1] = 0;
				j = 1;											 // присваиваем счётчик 1, что бы потом записать новое число, на только что обнуленую первую позицию массива operands[];
				operators[0] = str[i];							 // запоминаем знак
			}
			if (operators[0] == '-') {							 // если в массиве есть - , то выполним вычитание
				result = operands[0] - operands[1];
				operands[0] = result;
				operands[1] = 0;
				j = 1;
				operators[0] = str[i];
			}
			else {	
				operators[0] = str[i];							// если в массие нет опреций, то добавим эту операцию
			}
			oldNum1 = 0;										// обнуляем для дальшейшего вычисления
		}
	}
	
	return result;
}
int CharToInt(char c, int oldNum) { 
	oldNum = oldNum * 10 + (int)c - '0';
	return oldNum;
}

void push(char bracket) {
	struct NodeStack * node = &Stack; 
	if (node->head == NULL) {				// если голова Стека пуста, то создаём её и присваиваем ей скобку
		node->head = new NodeStack;
		node->head->brackets = bracket;
	}
	else {									// иначе, создаём новую "голову" Стека и создаём указатель новой "головы" на старую "голову" Стека
		NodeStack * temp = node->head;
		node->head = new NodeStack;
		node->head->brackets = bracket;
		node->head->pDown = temp;
	}
}

char pop()
{
	struct NodeStack * node = &Stack;
	NodeStack * temp = node->head;			// сохраняем старую "голову" Стека
	char oldBracket = node->head->brackets; // сохраняем значение старой "головы" Стека, что бы потом её вернуть, после удаления самой "головы" Стека
	node->head = node->head->pDown;			// переназначаем указатель старой "головы" на новую "голову"
	delete temp;							// удаляем старую "голову" Стека
	return oldBracket;
}

void show()
{
	struct NodeStack * node = &Stack;
	NodeStack * temp = node->head;
	while (temp != NULL) {					// Пока существуют узлы Стека выводим их, постепенно опускаясь в конец Стека
		cout << temp->brackets << " ";
		temp = temp->pDown;
	}
}
char top() {
	struct NodeStack * node = &Stack;
	if (node->head != NULL) {
		return node->head->brackets;
	}
	return -1;
	
}

int Task2(string str) {
	struct NodeStack * node = &Stack;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			push(str[i]);
		}else if (str[i] == ')') {
			if (top() == '(') {
				pop();
			}
			else {
				return -1;
			}
		}else if (str[i] == ']') {
			if (top() == '[') {
				pop();
			}
			else {
				return -1;
			}
		}else if (str[i] == '}') {
			if (top() == '{') {
				pop();
			}
			else {
				return -1;
			}
		}
	}
	if (node->head == NULL) {
		return 0;
	}
	else {
		return -1;
	}
}