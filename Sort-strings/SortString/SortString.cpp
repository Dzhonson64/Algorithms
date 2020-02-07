// SortString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
int length(char * str);
int flagStr(char * str1, char * str2);
void comparison(char ** str, int N);
int main() {
	int N;
	scanf("%i", &N);
	fflush(stdin);
	char ** string = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) {
		gets_s(&string);
	}

	comparison(string, N);
	for (int i = 0; i < N; i++) {
		puts((char *)string);
	}

	getch();
}

void comparison(char ** str, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - i; j++) {
			printf("%i", flagStr(str[i], str[i + 1]));
			if (flagStr(str[i], str[i + 1])) {
				char * temp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = temp;
			}
		}
	}
}
int length(char * str) {
	int i = 0;
	for (; str[i] != '\0'; i++);
	return i;
}
int flagStr(char * str1, char * str2) {

	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
		printf("%c - %c \n ", str1[i], str2[i]);
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] == str2[i]) {
			continue;
		}
	}
	return 0;
}