#include "Graph.h"
#include <string>
#include <cmath>


Graph::Graph(): time(0)
{
	vertexes = new std::list<Vertex*>;
	edges = new std::list<Edge>;
}


Graph::~Graph()
{
}
void Graph::addVertex(Vertex& v)
{
	vertexes->push_back(&v);
}
void Graph::addVertex(Vertex& v, int posX, int posY)
{
	v.x = posX;
	v.y = posY;
	vertexes->push_back(&v);
}

void Graph::addEdge(Vertex& from, Vertex& to, int weight, bool oriented)
{
	Edge newEdge = Edge(from, to, weight); // ������ ����� �� ���� ������: �� ����� ������� ������� ����� � � ����� �������
	edges->push_back(newEdge);		// ��������� � ������ ����
	if (oriented == false) {
		/* ���� ��������������� => ������ ���� �����, �� ������ ������� ������� */
		Edge newEdge_2 = Edge(to, from, weight);
		edges->push_back(newEdge_2);
		
	}

}
void Graph::addEdge(Vertex& from, Vertex& to, bool oriented)
{
	Edge newEdge = Edge(from, to); // ������ ����� �� ���� ������: �� ����� ������� ������� ����� � � ����� �������
	edges->push_back(newEdge);		// ��������� � ������ ����
	if (oriented == false) {
		/* ���� ��������������� => ������ ���� �����, �� ������ ������� ������� */
		Edge newEdge_2 = Edge(to, from);
		edges->push_back(newEdge_2);
	}


}

std::list<Vertex*>* Graph::getVertexList(Vertex& vertex)
{
	std::list<Vertex*>* result = new std::list<Vertex*>; // �������������� ������ ��������� ��� ������� vertex
	for (std::list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertex) {
			/* � ������ ���� ���� ������� vertex, ������� ��������� �������, �� ������� ������� �����*/
			result->push_back(i->to); // �� � ������ ��������� ��������� �������, � ������� ������ �����
		}
	}
	return result;
}

void Graph::relax(Vertex& to, Vertex& from, int weight)
{
	if (to.distance > from.distance + weight) {
		/* ��������� �� ��������� ������� (from) + ��� ����� ������ ������ ��������� ������� (to) */
		to.distance = from.distance + weight; // ��������� �� ����� ����������� ����������
		to.predecessor = &from; // ��������� ������ (������������ ���� ��������� ����������� ����)
	}
}

void Graph::initGraph(Graph& graph, Vertex& start)
{
	for (auto i : *vertexes) {
		// ���� �������� ����������� ��������� ����. ����������
		i->distance = INF;
		i->distanceF = INF;
	}
	start.distance = 0; // ��������� ������� �������� 0, �.�. ���������� �� ��������� �� ��������� ������� ���� 0
}



int Graph::getEdgeWeght(Vertex& from, Vertex& to)
{
	for (auto i : *edges) {
		if (i.from == &from && i.to == &to) {
			return i.weight;
		}
	}
	return 0;
}

double Graph::heuristic(Vertex& current, Vertex& finish)
{
	//return std::sqrt(std::abs((finish.x - current.x)* (finish.x - current.x)) + std::abs((finish.y - current.y)* (finish.y - current.y)));
	return std::abs(finish.x - current.x) + std::abs(finish.y - current.y);
}
