// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

void word(char * string, char * word);
int length(char * string);
void show(char * string);
void quickSort(char * arr, int left, int right);
int main()
{
	char string[50];
	char words[50];
	gets_s(string);
	word(string, words);
	show(words);
}
void word(char * string, char * word) {
	int len = length(string);
	int countBrackets = 0;
	int j = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '(') {
			countBrackets++;
			i++;
			while (true){
				if (string[i] == '(') {
					countBrackets++;
				}
				if (string[i] == ')') {
					countBrackets--;
				}
				if (countBrackets == 0) break;
				word[j] = string[i];
				quickSort(word, 0, j);
				j++;
				i++;
			}
		}
	}
	word[j] = '\0';
}

void show(char * string) {
	for (int i = 0; string[i] != '\0'; i++) {
		std::cout << string[i];
	}
}
int length(char * string)
{
	int i = 0;
	for (; string[i] != '\0'; i++);
	return i;
}



void quickSort(char * arr, int left, int right)
{
	int l = left;
	int r = right;
	int middle = arr[(left + right) / 2];
	while (l <= r) {
		while (arr[l] < middle) l++;
		while (arr[r] > middle) r--;
		if (l <= r) {
			int temp = arr[r];
			arr[r] = arr[l];
			arr[l] = temp;
			r--;
			l++;
		}
	}
	if (l < right) {
		quickSort(arr, l, right);
	}
	if (r > left) {
		quickSort(arr, left, r);
	}
}
