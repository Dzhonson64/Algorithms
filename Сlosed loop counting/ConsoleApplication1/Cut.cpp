#include "pch.h"
#include "Cut.h"

Cut::Cut()
{
}

Cut::Cut(int M, int N)
{
	this->M = M;
	this->N = N;
	area = new int*[N];
	for (int i = 0; i < N; i++) {
		area[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			area[i][j] = 1;
		}
	}

}


Cut::~Cut()
{
	for (int i = 0; i < N; i++) {
		delete area[i];
	}
	delete area;
}

int Cut::fill(int x, int y)
{
	area[y][x] = 2;
	if (x + 1 < M && area[y][x + 1] == 1 ) { // если свободно, идём вправо
		fill(x + 1, y);
	}
	if (y + 1 < N && area[y + 1][x] == 1 ) { //  если свободно, идём вниз
		fill(x, y + 1);
	}
	if (x - 1 >= 0 && area[y][x - 1] == 1 ) { //  если свободно, идём влево
		fill(x - 1, y);
	}
	if (y - 1 >= 0 && area[y - 1][x] == 1 ) { //  если свободно, идём вверх
		fill(x, y - 1);
	}
	return 0;
}

void Cut::addPos(int x, int y)
{
	area[y][x] = 0;
}

int Cut::fillAndCount()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (area[i][j] == 1) { // если есть невырезанная часть , то запоняем её и увеличиваем счётчки кусков
				fill(j, i);
				count++;
			}
		}
	}
	return count;
}
void Cut::showArea()
{
	cout << "\t\tList cages\n\n";

	cout << "\t    ";
	for (int i = 0; i < M; i++) {
		cout << i << " ";
	}

	cout << endl;
	cout << "\t  ";

	cout << "+ ";
	for (int i = 0; i < M; i++) {
		cout << "- ";
	}
	cout << "-> X";
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << "\t";
		cout << i << " | ";
		for (int j = 0; j < M; j++) {
			cout << area[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\t  v " << endl;
	cout << "\t  Y " << endl;
}



