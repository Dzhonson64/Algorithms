// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
int Task2(int * arr1, int size1, int * arr2, int size2, int * arr3, int size3);
void Task3(int * arr1, int size1);
int main()
{
	const int size1 = 5;
	const int size2 = 4;
	const int size3 = 8;
	
	int arr1[size1] = { 3, 4, 10, 20, 22 };
	int arr2[size2] = { 0, 1, 5, 19};
	int arr3[size3] = { -1, 2, 3, 4, 10, 20, 22, 30 };
	std::cout << Task2(arr1, size1, arr2, size2, arr3, size3) << std::endl;

	const int size4 = 6;
	int arr4[size4] = {100, 0, 1100, 51, 51, 6};
	Task3(arr4, size4);
}

int Task2(int * arr1, int size1, int * arr2, int size2, int * arr3, int size3)
{
	/* Инициализируем счётчики для массива  arr1, arr2 , arr3 соответственно*/
	int i = 0;
	int j = 0;
	int k = 0;
	try
	{
		while (i < size1 && j < size2 && k < size3) {
			/* Ни один из массивов не закончился */

			if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
				/* Элемент есть во всех трёх массивах */

				return arr1[i];
			}
			else if (arr1[i] < arr2[j]) {
				i++; // переходим к рассмотрению следующего элемента в первом массиве, т.к. получается, что в первом массиве числа по значению отстают от значений второго массива
			}
			else if (arr2[j] < arr3[k]) {
				j++; // переходим к рассмотрению следующего элемента во втором массиве, т.к. получается, что во втором массиве числа по значению отстают от значений третьего массива
			}
			else {
				k++; // переходим к рассмотрению следующего элемента в третьем массиве, т.к. получается, что в третьем массиве числа по значению отстают от значений первого массива
			}
		}
		throw;
	}
	catch (const std::exception&)
	{
		std::cout << "Not found the number" << std::endl;
		return 0;
	}
	
	
}

void Task3(int * arr1, int size1)
{
	/* Инициализируем переменные хранящие три min числа первыми тремя элементами массива */
	int min1 = arr1[0]; 
	int min2 = arr1[1];
	int min3 = arr1[2];

	 
	/* Сортируем первые начальные мин. элементы массива, так что  min1 < min2 < min3 */
	if (min2 < min1) {
		int temp = min1;
		min1 = min2;
		min2 = temp;
	}
	if (min2 > min3) {
		int temp = min2;
		min2 = min3;
		min3 = temp;
	}
	if (min2 < min1) {
		int temp = min1;
		min1 = min2;
		min2 = temp;
	}

	for (int i = 3; i < size1; i++) {
		if (arr1[i] <= min1) {
			/* Элемент массива меньшем, чем первый минимальный элемент */

			/* Сдвигаем минимальные элементы, которые справа относительно min1, вправо, и на обновляем min1*/
			min3 = min2;
			min2 = min1;
			min1 = arr1[i];
		}
		else if (arr1[i] < min2) {
			/* Элемент массива меньшем, чем второй минимально найденный элемент */

			/* Сдвигаем минимальные элементы, которые справа  относительно min2, вправо, и на обновляем min2*/
			min3 = min2;
			min2 = arr1[i];
		}
		else if (arr1[i] < min3) {
			/* Элемент массива меньшем, чем третий минимально найденный элемент */

			/* Обновляем min3 */
			min3 = arr1[i];
		}
	}
	std::cout << "min1 - " << min1 << std::endl;
	std::cout << "min2 - " << min2 << std::endl;
	std::cout << "min3 - " << min3 << std::endl;
}
