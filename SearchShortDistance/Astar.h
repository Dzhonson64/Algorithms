#pragma once

#include "Graph.h"

/* 
	�������� A* ����� ����������� �� ���� 3-� ����������, �� �� �� �� ���� ������ ��������. ��������, ���� �������������, A* �������������� ����� ���������� ����,
	���� ��������� ������� �� ������ ��������� ����������. ����� ��������� ���������� ������, A* ������������ � �������� ��������.
	����� ��������� ���������� ������, A* ������������ � ������ ����� �� ���������� ������� ����������.
*/
class Astar : public Graph
{
private:
	std::list<Vertex*>* opened = NULL; /* ������, ������� ��������������� �� ����� ���������
													(������������� �� ���-�� ���������� ������ ������ � ���������� ����� ����������� � 0).
													!!!� ������ ������ �� ������, � �������� ���� (������� � �����������)!!!
											*/
	std::list<Vertex*>* closed = NULL;	// ������������� �������
	Vertex* getMinVertex();	// �.�. � �� ����������� �������� ����, �� �������� ����� ����������� ����� ������� � ���. distance
public:
	Astar() :Graph()
	{
	};
	void AstarAlgorithm(Astar& graph, Vertex& startVertex, Vertex& finishVertex, bool stringData = false);	// �������� �������� ��������
	void showPath(Vertex& finishVertex, bool stringData = false);	// ����� ������ � ���� ������ ������, �� ������� ������� ����
	bool isOpened(Vertex& vertex);
	bool isClosed(Vertex& vertex);
	std::list<Vertex*>* getVertexList(Vertex & vertex);
};


