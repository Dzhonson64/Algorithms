#pragma once
#include "Vertex.h"
#include "Graph.h"


/*  
	�������� ����� - �������� ��������� ����� ���������� ���� �� ����� ������� ����� �� ���� ���������, ���� ��� ������,
	� ������� ���� ����� ����� ���� ��������������.��� �� �����, � ����� �� ������ ���� ������ �������������� ���� (�����, ��� ����� ����� ���������� ����� ������������), ���������� �� ��������� �������,
	����� ������ � ���������� ����� �������� �������������.��� ���� �������� ����� - �������� ��������� ���������� ������� ������ �������������� ����,
	���������� �� ��������� �������.
*/


class BellmanFordAlgorithm : public Graph
{
public:
	BellmanFordAlgorithm() : Graph() {}; 
	~BellmanFordAlgorithm();
	bool BellmanFord(BellmanFordAlgorithm& graph, Vertex& vertex, Vertex& finishVertex);
	void showPath(Vertex& finitshVertex, bool showStr = false);	// ����� ������������ ���� (������)
};

