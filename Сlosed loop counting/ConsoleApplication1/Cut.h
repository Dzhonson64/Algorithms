#pragma once
#include <iostream>
using namespace std;

class Cut
{
private:
	int count = 0; // ���-�� ���������� ������
	int M;
	int N;
	int ** area; // ������ �������� ���� (1 - ��� ������������ �����, � 0 - ���������� �����, � 2 - ����������� �����)
	int fill(int x, int y); // ���������� �������
public:
	Cut();
	Cut(int M, int N);
	~Cut();
	
	void addPos(int x, int y); // ���������� ������� � ������������
	int fillAndCount(); // ����� ����� � ������� ������
	void showArea(); // ����� ���� �� �����
};

