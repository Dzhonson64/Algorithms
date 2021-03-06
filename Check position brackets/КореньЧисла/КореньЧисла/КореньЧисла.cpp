#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;
long double firBinSearch(double a, int n, long double R) {
	long double L = 0;
	while (R - L > 1e-10) { // пока разница между R и L приблизительно не равны с точность 1^-10
		/*
			итерацию можно рассмотреть в виде отрезка:
			|---------------|
			^		^		^
			|		|		|
			(1)		(2)		(3)

			(1) - число (пермен. L) в квадрате, которое меньше заданного числа (пермен. А);
			(2) - заданное число (пермен. А), корень которого надо найти;
			(3) - число (пермен. R) в квадрате, которое, больше заданного числа (пермен. А);
		*/
		long double M = (L + R) / 2; /* увелчиваем отрезок с попомощью R + L, который либо равень пермен. А (сначала), либо больше A,
										промежуток R + L и делим пополам, а дальше наблюдаем за числом M
									*/
									/*
										|-----------------------|
										^		^	^	^		^
										|		|	|	|		|
										(1)		(2)	(3)	(2)		(4)
										(1) - 0;
										(2) - примерное нахождение A (зависит от M, или М > A, или M < A)
										(3) - M
										(4) - R+L;
									*/
		if (pow(M, n) < a) { // если у нас число M в квадрате меньше числа А, то мы его закидваем в  переменную L, указывающую левую границу нового отрезка
			L = M;
		}
		else { // иначе, если число M больше числа, то записываем в переменную R, указывающую правую границу нового отрезка
			R = M;
		}


	}
	/*
		В результате мы постепенно сужаем отрезок, тем самым приближаемся к числу, которые в квадрате примерно равно A
	*/
	return R;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	double a;
	std::cin >> a >> n;
	if (a >= 1) {
		//double start = clock();
		double result = firBinSearch(a, n, a);
		//double end = clock();
		//double time = (start - end) / CLOCKS_PER_SEC;
		std::cout << std::fixed << std::setprecision(10) << result << endl;
		//std::cout << "Время выполнения программы: " << time << endl;
	}
	else {
		if (a < 1) {
			//double start = clock();
			double result = firBinSearch(a, n, 1);
			//double end = clock();
			std::cout << std::fixed << std::setprecision(10) << result;
			//std::cout << "Время выполнения программы: " << (end - start) / 1000.0 << " сек" << endl;
		}
	}
	return 0;
}