// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

double summ(double num1, double num2);
double subtraction(double num1, double num2);
double division(double num1, double num2);
double mult(double num1, double num2);
int exec(char op, double num1, double num2);
int priority(char op);
double calc(char* lex);
int main()
{
	char str[100];
	gets_s(str);
	calc(str);
}
double calc(char* lex) {
	stack<double> operands;
	stack<char> operators;
	char * num;
	int k = 0;
	for (int i = 0; lex[i] != '\0'; i++) {
		if (lex[i]>= '0' && lex[i] <= '9') {

			while (lex[i] >= '0' && lex[i] <= '9' || lex[i] == '.') {
				k++;
				i++;
			}
			num = (char*)malloc(sizeof(char)*k+1);
			i = i - k;
			k = 0;
			while (lex[i] >= '0' && lex[i] <= '9' || lex[i] == '.') num[k++] = lex[i++];
			num[k] = '\0';
			i--;

			operands.push(atof(num));
		}
		else if ( lex[i] == '+'	||  lex[i] == '-'|| lex[i] == '/' || lex[i] == '*'){
			if (operators.empty() || priority(lex[i]) > priority(operators.top())) {
				operators.push(lex[i]);
			}else  if (priority(lex[i]) < priority(operators.top())) {
				exec(lex[i], operands.top(), operands.top());
				operands.pop();
				operands.pop();
			}else if (priority(lex[i]) == priority(operators.top())) {
				operators.push(lex[i]);
			}
		}
		
	}
	return 0;
}

int exec(char op, double num1, double num2) {
	if (op == '+') return summ(num1, num2);
	else if (op == '/') return division(num2, num1);
	else if (op == '*') return mult(num1, num2);
	else if (op == '-') return subtraction(num2, num1);
	else if (op == '^') return pow(num2, num1);
}
int priority(char op) {
	switch (op)
	{
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default:
		break;
	}
}
double summ(double num1, double num2) {
	return num1 + num2;
}
double subtraction(double num1, double num2) {
	return num1 - num2;
}
double division(double num1, double num2) {
	return num1 / num2;
}
double mult(double num1, double num2) {
	return num1 * num2;
}