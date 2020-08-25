// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void encode(FILE * f1, FILE * encrypt, FILE * f2);	// кодирование сообщения из encrypt в f1, отсносительно текста f2
void decode(FILE * f1, FILE * f2); // раскодирование сообщения из f1 в f2
int main()
{
	FILE * f2 = fopen("input.txt", "r+b");					 // исходный текст
	FILE * encryptInput = fopen("encryption.txt", "r");		 // исходное сообщение, относительно которого кодируется f1
	FILE * f1 = fopen("output.txt", "w+b");					 // закодированный текст
	FILE * encryptOutput = fopen( "encryptOutput.txt", "w"); // текст раскодированного сообщения
	if (f1 != NULL  && encryptInput != NULL && f2 != NULL && encryptOutput != NULL) {
		encode(f1, encryptInput, f2);
		decode(f1, encryptOutput);
	}
	else {
		std::cout << "Files were not opened" << std::endl;
	}
	fclose(f1);
	fclose(encryptInput);
	fclose(f2);
	fclose(encryptOutput);
}

void encode(FILE * f1, FILE * encrypt, FILE * f2)
{
	char str[256];				// массив, содержащий строку из файлового потока f1
	int binEncriptCharNum[8];	// массив, содрежащий двоичный код символа из потока encrypt

	while(!feof(f2)) {
		/* Поток f1 не закончился */

		char encriptChar = fgetc(encrypt);		// запоминаем первый символ из сообщения для кодирования
		
		int encriptCharNum = int(encriptChar);	// переводим char в ASCII код
		for (int i = 7; i >= 0; i--) {
			/* Заполняем массив соответствующими битами символа */
			/* Начинаем заполнять массив с конца, т.к. c помощью %2 находятся биты с конца 8-битной маски символа */
			int binNum = encriptCharNum % 2;
			binEncriptCharNum[i] = binNum;
			encriptCharNum = encriptCharNum / 2;
		}

		for (int i = 0; i < 8; i++) {
			
			/* Проходим по 8 строк, т.к. у нас код символа из 8 бит */

			fgets(str, 256, f2);	// берём строку из исходного текста
			if (feof(f2)) {
				/* Закончился исходный текст */

				break;
			}
			int length = strlen(str);		// вычисляем длину строки
			if (binEncriptCharNum[i] == 1 && !feof(encrypt)) {
				/* Бит символа равен 1 и сообщение не закончилось */

				
				str[length + 1] = str[length];		// переставляем '\0' на позицию вперёд
				str[length] = str[length - 1];		// переставляем '\n' на позицию вперёд
				str[length - 1] = str[length - 2];	// переставляем '\r' на позицию вперёд
				str[length - 2] = ' ';				// на оставшееся место вставляем пробел
				fprintf(f1, "%s", str);			// вставляем изменённую строку в закодированный файл
			}
			else {
				/* Бит символа равен 0 или закончилось сообщение*/

				fprintf(f1, "%s", str); // вставляем неизменённую строку в закодированный файл
			}
			
		}
	}
	
}

void decode(FILE * f1, FILE * f2) {
	fseek(f1, 0, SEEK_SET);	// возвращаем указатель на начало файла
	char str[256];			// массив, содержащий строку из файлового потока f1
	
	
	while (!feof(f1)) {
		/* Поток f1 не закончился */

		int stepen = 128;	// переменная, хранящая двойку в n-ой степени (первоначально n = 7)
		int num = 0;		// переменная, хранящая число переведённое из двоичной в десятичную сс
		for (int i = 0; i < 8; i++) {
			fgets(str, 256, f1);	// берём строку из закодированного текста
			if (str[strlen(str) - 3] == ' ') {
				/* Символ перед '\0', '\n' и '\r' - пробел */

				num += stepen;		// прибаляем к num двойку в степени 7-i (stepen)
			}
			stepen /= 2; // находим, чему равно два в степени 6-i
		}
		if (char(num) == '\0') {
			/* Раскодировано всё сообщение */
			break;
		}
		fprintf(f2, "%c", char(num)); // вставляем символ в файл с раскодированным сообщением
	}
}