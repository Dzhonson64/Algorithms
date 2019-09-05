#pragma once
#include "Vertex.h"
#include "Graph.h"
#include <functional>
#include <queue>
#include <vector>
#include <list>


/*
	���������� ���������� ����� �� ����� ������� �� ���� ��������� � ��������������� ���������� �����,
	��� �������, ��� ��� ����� � ����� ����� ��������������� ����.
*/






class Dijksrta : public Graph
{
private:
	std::list<Vertex*> * considerVertexes = NULL; /* ������, ������� ��������������� �� ����� ���������
													(������������� �� ���-�� ���������� ������ ������ � ���������� ����� ����������� � 0).
													!!!� ������ ������ �� ������, � �������� ���� (������� � �����������)!!!
												*/
	//std::vector <Vertex*> * numbersVertexes = NULL;
	Vertex* getMinVertex();	// �.�. � �� ����������� �������� ����, �� �������� ����� ����������� ����� ������� � ���. distance
public:
	Dijksrta() :Graph()
	{
	};
	~Dijksrta();
	void DijksrtaAlgorithm(Dijksrta & graph, Vertex & startVertex, bool stringData = false);	// �������� �������� ��������
	void showPath(Vertex& finishVertex, bool stringData = false);	// ����� ������ � ���� ������ ������, �� ������� ������� ����
	
};



