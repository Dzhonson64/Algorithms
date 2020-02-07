// longАrithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Num {
	const int base = 10; // макс. число, которое может храниться в ячейки
	const int baseLen = 1; // макс. длина, которая может храниться в ячейке
	const int maxLen = 10; // фактически число ячеек в массиве
} ConstNum;
void read(long long num, int * arr, int size);
int length(char * str);
void print(int * arr);
void summ(int * arr1, int * arr2, int * res);
int revers(int num);
void molS(int * arr1, long long num, int * res); // умножение длинного на короткое
void sub(int * arr1, int * arr2, int * res); // вычитание
void divS(int * arr1, long long num, int * res);// деление длинного на короткое
void comparison(int * arr1, int * arr2);
void mull(int * arr1, int * arr2, int * res);
int main()
{
	struct Num * numArr = &ConstNum;
	long long num1 = 999999;
	long long num2 = 999999;
	long long num3 = 3;
	long long temp;
	const int maxLen = 100;
	int arr1[maxLen];
	int arr2[maxLen];
	int res[maxLen];
	read(num1, arr1, maxLen);
	read(num2, arr2, maxLen);
	//mull(arr1, arr1, res);
	print(arr1);

	
}
void initArr(int * arr) {
	struct Num * numArr = &ConstNum;
	for (int i = 0; i < numArr->maxLen; i++) {
		arr[i] = 0;
	}
}
void read(long long num, int * arr, int size) {
	struct Num * numArr = &ConstNum;
	initArr(arr);
	int i = 0;
	int flag = 0;
	while (num > 0) {
		if (flag % numArr->baseLen == 0 && flag != 0) {
			arr[i] = revers(arr[i]); // делаем переворот для приведения в нормальный вид, а не превёрнутый, чтобы легче выводить и делать ариф. операции 
			i++;
		}
		arr[i] = arr[i] * 10 + num % 10;
		flag++;
		num = num / 10;
	}
	arr[i] = revers(arr[i]);
}
void print(int * arr) {
	struct Num * numArr = &ConstNum;
	int i = numArr->maxLen-1;
	while (arr[i] == 0) {// пробегаеммся с конца масива до первого значащей цифры (не равное 0)
		i--;
	}

	//if (i == 0) cout << 0; // если массив пуст, то 0 !!!ПРОРАБОАТЬ ЭТОТ МОМЕНТ, КОГДА МАССИВ ПУСТ!!!


	cout << arr[i]; // выводим эту первую цифру 
	
	cout << " ";
	i--;
	while (i >= 0) { // выводим остальные и начиная с последней цифры числа, т.к. в массиве число перевёрнуто и его нужно опять же перевернуть
		int temp = numArr->base;
		int tempBaseLine = numArr->baseLen;
		while(temp > 1 && tempBaseLine > 0){
			temp = temp / 10;
			cout << arr[i];
			arr[i] = arr[i] % temp;
			tempBaseLine--;
		}
		cout << " ";
		i--;
	}
}
void summ(int * arr1, int * arr2, int * res) {
	struct Num * numArr = &ConstNum;
	initArr(res);
	int c = 0; // перенос
	for (int i = 0; i < numArr->maxLen; i++) {
		c = arr1[i] + arr2[i] + c; /* складываем число из соответвующих ячеек первого и второго массива и плюс "с",
										т.к. если на следующей число-ячейки будут складываться другие числа и плюс лишнее число с прошлого суммирования.
										А само "с"?, к котормо присваиваем в себе может содеражть как число больше base, так и меньше. И дальше это мы решаем*/
		res[i] = c % numArr->base; // Мы "с" делим на base, и в результат уходит или часть числа которая всегда меньше base, если число "c" > base или всё число целиком
		c = c / numArr->base; // если часть ушла в res[i], то мы отсекаем первые несколько цифр, которые сделали число > base и это у нас дальше перейдёт в слудующую число-ячеку
	}
}
int revers(int num) {
	struct Num * numArr = &ConstNum;
	int temp = 0;
	int i = 0;
	while (i < numArr->baseLen) {
		temp = num % 10 + temp * 10;
		num = num / 10;
		i++;
	}
	return temp;
}
void molS(int * arr1, long long num, int * res) {
	struct Num * numArr = &ConstNum;
	int c = 0;
	for (int i = 0; i < numArr->maxLen; i++) {
		c = arr1[i] * num + c;
		res[i] = c % numArr->base;
		c = c / numArr->base;
	}
}
void sub(int * arr1, int * arr2, int * res) {
	struct Num * numArr = &ConstNum;
	int c = 0;
	for (int i = 0; i < numArr->maxLen; i++) {
		c = c + arr1[i] - arr2[i];
		res[i] = (c + numArr->base) % numArr->base;
		c = (c + numArr->base) / numArr->base - 1;
	}
}
void divS(int * arr1, long long num, int * res) {
	struct Num * numArr = &ConstNum;
	int c = 0;
	for (int i = numArr->maxLen-1; i >= 0; i--) {
		c = c * numArr->base + arr1[i];
		res[i] = c / num;
		c = c % num;
	}
}
void comparison(int * arr1, int * arr2) {
	struct Num * numArr = &ConstNum;
	bool flag = false;
	for (int i = 0; i < numArr->maxLen; i++) {
		if (arr1[i] < arr2[i]) {
			flag = true;
			cout << "Arr1 < Arr2" << endl;
			break;
		}
		if (arr1[i] > arr2[i]) {
			flag = true;
			cout << "Arr1 > Arr2" << endl;
			break;
		}
	}
	if (flag == false) {
		cout << "Arr1 == Arr2" << endl;
	}
}
void mull(int * arr1, int * arr2, int * res) {
	struct Num * numArr = &ConstNum;
	for (int i = 0; i < numArr->maxLen; i++) {
		int c = 0;
		for (int j = i; j < numArr->maxLen; j++) {
			c = c + arr2[i] * arr1[i] + res[i];
			res[j] = c % numArr->base;
			c = c / numArr->base;
		}
	}
}
int length(char * str) {
	int i = 0;
	for (; str[i] != '\0'; i++);
	return i;
}
/*char copy(char * str, int newLen, int count) {
	char * newStr = new char[newLen];
	for (int i = 0; i < newLen; i++) {
		newStr[i] = str[i];
	}

}*/