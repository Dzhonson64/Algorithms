#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <queue>
#include <list>
#include <vector>
class Graph
{
protected:
	const unsigned long int INF = 4294967295;	// �����, ������� ���������������� ��� �������� ������ ����� (���� �������������)
	int time;
	std::list<Vertex*>* vertexes;						// ������ ���� ������
	std::list<Edge>* edges;								// ������ ����
public:
	Graph();
	~Graph();
	void addVertex(Vertex& v);
	void addVertex(Vertex& v, int posX, int posY);						// ���������� �������
	void addEdge(Vertex& from, Vertex& to, bool oriented = false); // ���������� ����� (oriented = false - ���� �����������������, oriented = true - ���������������)
	void addEdge(Vertex& from, Vertex& to, int weight = 0, bool oriented = false); // ���������� ����� (oriented = false - ���� �����������������, oriented = true - ���������������)
	std::list<Vertex*>* getVertexList(Vertex& vertex);	// ��������� ������ ��������� ��� ������� vertex
	void relax(Vertex& to, Vertex& from, int weight);	// ���������� ������� - ���������� ��������� �� ������� "to" �� ����� �����������
	void initGraph(Graph& graph, Vertex& start);		// ������������� ��������� �� ������, ��� ��������� ������� - "start"	
	int getEdgeWeght(Vertex& from, Vertex& to);			// ��������� ���� �����
	double heuristic(Vertex & current, Vertex & finish);
};

