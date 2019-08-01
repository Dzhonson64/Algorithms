#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <stack> 
#include <list>
#include <map>
using namespace std;
class EulerWay
{
private:
	Vertex * start;
	int time;	// ����� ����������� �����, ������������� ���� �������� ����� ��������� � ������� � ��� ���������
	int col;	// ����� ���������� �����������
public:
	EulerWay();
	~EulerWay();
	void findEulerPath(Vertex & vertex);			// ��������� ������ ���������� ����
	list<Vertex*> * vertexes;						// ������ ������ �����
	stack<Vertex*> * st;							// ���� ������, ������� ������ ���������� �������
	list<Edge> * edges;								// ������ ����
	void addVertex(Vertex & v);						// ���������� ����� �������
	void addEdge(Vertex & from, Vertex & to, bool oriented = false); // ���������� ������ ����� (oriented = false - ���� ����������������, oriented = true - ���������������)
	list<Vertex*>* getVertexList(Vertex & vertex);	// ��������� ������ ��������� ��� ������� vertex
	int getCountVertexesTo(Vertex & v);				// ��������� ������� �������
	bool checkForEulerPath(EulerWay & graph);		// �������� �� ����������� ���������� ����/�����
	void removeEdge(Vertex & vertexFrom, Vertex & vertexTo);	// �������� �����
	void eulerPath(EulerWay & graph);							// ��������� �-�� ��� ��������� ������ ���������� ����
	void DFS(EulerWay & graph, Vertex & vertex);				// ����� � �������
};