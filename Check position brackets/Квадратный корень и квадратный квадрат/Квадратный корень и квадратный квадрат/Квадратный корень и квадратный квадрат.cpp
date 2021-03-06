#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double check(long double x) {
	return pow(x, 2) + sqrt(x);
}
/* Та же аналогия, что и в программе "КореньЧисла":
	программу можно представить ввиде отрезка, где слева L, а справа R, а по середине число C,
	только отличие в проверке вырадения "pow(x, 2) + sqrt(x)". Если оно меньше С, то в левую переменную L, иначе вправую R,
	и таким образом постепенно приближаемся к ответу, уменьшая отрезок
*/
long double binSearch(double c) {
	double R = 1e10, L = 0, M;
	while ((R - L) > 1e-10) {
		cout << "\n\tНачало итерации" << endl;
		cout << "fabs(R - L) > 1e-10\t" << R - L << " < " << 1e-10 << endl;
		M = (L + R) / 2;
		cout << "(L + R) / 2\t" << "M = " << M << endl;
		if (check(M) < c) {
			cout << "check(M) - c\t" << check(M) - c << endl;
			L = M;
			cout << "L = M\tL=" << M << endl;
		}
		else {
			R = M;
			cout << "R = M\tR=" << M << endl;
		}
	}
	return R;
}

int main() {
	setlocale(LC_ALL, "rus");
	double c;
	cin >> c;
	double result = binSearch(c);
	cout << fixed << setprecision(6) << result;
	return 0;
}