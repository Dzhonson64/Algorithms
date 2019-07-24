#include "pch.h"
#include "DFS.h"
#include <list>
DFS::DFS()
{
	start = NULL;
	vertexes = new list<Vertex*>;
	vertexesSort = new list<Vertex*>;
	edges = new std::list<Edge>;
	time = 0;
}


DFS::~DFS()
{
}
void DFS::DFS_algoritm(DFS & graph)
{
	time = 0;

	for (auto i : *vertexes) {
		/* ���������� �� ���� �������� ����� */
		if (i->color == 'W') {
			/* ������� ����� => �������� � � ������������ */
			DFS_visit(graph, *i);
		}
	}
}

void DFS::DFS_visit(DFS & graph, Vertex & vertex)
{
	
	vertex.color = 'G';									// �������� �, ��� ������������
	list<Vertex*> * vertexList = getVertexList(vertex); // ���������� ������ ��������� ��� ������� vertex
	time++;
	vertex.distance = time;
	for (auto i : *vertexList) {
		/* �������� �� ���� ������� �������� */
		
		if (i->color == 'W') {

			
			/* ������� ��������������� */
			i->predecessor = &vertex;	// ���������� �� ����� ������� ������
			
			DFS_visit(graph, *i);		// ������������� ��� ������� �������
		}
	}
	/* ��� ������� ������� �����, �� �������� �������� ��� ������������� ������� */
	vertex.color = 'B';
	time++;
	vertex.finish = time;
	vertexesSort->push_front(&vertex); // ��������� � ������ ��� ������������� ������� (����� ����������� � ����)
	
}

void DFS::addVertex(Vertex & v)
{
	vertexes->push_back(&v);
}

void DFS::addEdge(Vertex & from, Vertex & to, bool oriented)
{
	Edge newEdge = Edge(from, to); // ������ ����� �� ���� ������: �� ����� ������� ������� ����� � � ����� �������
	edges->push_back(newEdge);		// ��������� � ������ ����
	if (oriented == false) {
		/* ���� ��������������� => ������ ���� �����, �� ������ ������� ������� */
		Edge newEdge_2 = Edge(to, from);
		edges->push_back(newEdge_2);
	}


}

list<Vertex*> * DFS::getVertexList(Vertex & vertex)
{
	list<Vertex*> * result = new list<Vertex*>; // �������������� ������ ��������� ��� ������� vertex
	for (list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertex) {
			/* � ������ ���� ���� ������� vertex, ������� ��������� �������, �� ������� ������� �����*/
			result->push_back(i->to); // �� � ������ ��������� ��������� �������, � ������� ������ �����
		}
	}
	return result;
}
