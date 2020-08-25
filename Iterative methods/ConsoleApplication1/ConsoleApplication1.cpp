// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
int * map(int func(int), int * arr);
int * filter(bool func(int), int * arr);
int reduce(int func(int, int), int acc, int * arr);
int * zipWith(int func(int, int), int * arr1, int * arr2);
std::vector<int> takeWith(bool func(int), int * arr);

int square(int x);
int summ(int x, int acc = 0);
int summ2(int x1, int x2);
bool even(int x);
int main()
{
	int * arr = new int[4];
	int * newArr = new int[4];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 5;
	arr[3] = 11;

	int * arr2 = new int[4];
	arr2[0] = 1;
	arr2[1] = 2;
	arr2[2] = 5;
	arr2[3] = 11;

	newArr = zipWith(summ2, arr, arr2);
	//std::cout << a;
	for (int i = 0; i < 4; i++) {
		std::cout << newArr[i] << " ";
	}
}
int square(int x) { return x * x; };
bool even(int x) { return x % 2 == 0 ? true : false; };
int summ(int x, int acc) { return acc + x; }
int summ2(int x1, int x2) { return x1 + x2; };

int * map(int func(int), int * arr)
{	
	int size = _msize(arr) / sizeof(int);
	int * newArr = new int[size];
	for (int i = 0; i < size; i++) {
		newArr[i] = func(arr[i]);

	}
	return newArr;
}

int * filter(bool func(int), int * arr)
{
	int size = _msize(arr) / sizeof(int);
	int * newArr = new int[size];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (func(arr[i])) {
			newArr[j++] = arr[i];
		}
	}
	return newArr;
}

int reduce(int func(int, int), int acc, int * arr)
{
	int size = _msize(arr) / sizeof(int);
	for (int i = 0; i < size; i++) {
		acc = func(arr[i], acc);
	}
	return acc;
}

int * zipWith(int func(int, int), int * arr1, int * arr2)
{
	int size1 = _msize(arr1) / sizeof(int);
	int size2 = _msize(arr2) / sizeof(int);
	int * newArr;
	int maxSize;
	if (size1 > size2) {
		newArr = new int[size1];
		maxSize = size1;
	}
	else {
		newArr = new int[size2];
		maxSize = size2;
	}
	
	for (int i = 0; i < maxSize; i++) {
		if (i >= size1) {
			newArr[i] = func(0, arr2[i]);
		}
		else if (i >= size2) {
			newArr[i] = func(arr1[i], 0);
		}
		else {
			newArr[i] = func(arr1[i], arr2[i]);
		}
		
	}

	return newArr;

}

std::vector<int> takeWith(bool func(int), int * arr)
{

	int size1 = _msize(arr) / sizeof(int);
	std::vector<int> newArr;
	while(){

		if (func(arr[i])) {
			newArr.push_back();
		}
		
	}
	
	
	return nullptr;
}
