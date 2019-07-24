#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <queue> 
#include <list>
using namespace std;
class DFS
{
private:
	Vertex * start;
	int time;	// ����� ����� � ��������� ������������ ������� 
public:
	DFS();
	~DFS();
	void DFS_algoritm(DFS & graph); // ����� � �������
	void DFS_visit(DFS & graph, Vertex & vertex); // ����� � �������
	//queue<Vertex*> * pendingVertexes;				// ������� ������ ��� ����������� �� ������������ !!! ������ ����� �������������� ���� !!!
	list<Vertex*> * vertexes;						// ������ ���� ������
	list<Vertex*>*vertexesSort;						// ��������������� ������������� ������� �����
	list<Edge> * edges;								// ������ ����
	void addVertex(Vertex & v);						// ���������� �������
	void addEdge(Vertex & from, Vertex & to, bool oriented = false); // ���������� ����� (oriented = false - ���� �����������������, oriented = true - ���������������)
	list<Vertex*>* getVertexList(Vertex & vertex);	// ��������� ������ ��������� ��� ������� vertex
};

