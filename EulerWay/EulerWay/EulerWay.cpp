#include "pch.h"
#include "EulerWay.h"
#include <list>
#include "string"
EulerWay::EulerWay()
{
	start = NULL;
	vertexes = new list<Vertex*>;
	st = new stack<Vertex*>;
	edges = new std::list<Edge>;

}


EulerWay::~EulerWay()
{
}
void EulerWay::eulerPath(EulerWay & graph)
{
	if(checkForEulerPath(graph)) {
		/* ��������� ���� ���������� */
		findEulerPath(*vertexes->front());
	}
	else {
		/* ��������� ���� �� ���������� */
		std::cout << "This graph don't have euler way" << std::endl;
	}
}
void EulerWay::findEulerPath(Vertex & vertex)
{
	st->push(&vertex);
	while (!st->empty()) {
		/* ���� �� ������ */

		Vertex * v = st->top(); // ���� ������� � ������� �����
		list<Vertex*> * vertexList = getVertexList(*v);	// ������� ������� �������
		for (auto i : *vertexList) {
			st->push(i);	// ����� � ���� ������ ���������� ������� �� �������
			removeEdge(*v, *i);	// ������� ����� ����� ��������������� �������� � � �������
			break;
		}
		if (v == st->top()) {
			/* ������� ������� ����� 0, �.�. ������� ������ ���� 0 � ������ �� ���� � ���� �� ����������� */
			std::cout << v->str << " -> ";
			st->pop();
		}
	}

}


void EulerWay::addVertex(Vertex & v)
{
	vertexes->push_back(&v);
}

void EulerWay::addEdge(Vertex & from, Vertex & to, bool oriented)
{
	Edge newEdge = Edge(from, to);
	edges->push_back(newEdge);
	if (oriented == false) {

		Edge newEdge_2 = Edge(to, from);
		edges->push_back(newEdge_2);
	}


}

list<Vertex*> * EulerWay::getVertexList(Vertex & vertex)
{
	list<Vertex*> * result = new list<Vertex*>;
	for (list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertex) {
			/* ��������� ������� � ����� - ��� ������ ������� */
			result->push_back(i->to); // ���������� �������, ���� ��� ����� ���
		}
	}
	return result;
}

int EulerWay::getCountVertexesTo(Vertex & v)
{
	list<Vertex*> * listVertexes = getVertexList(v);
	int count = 0;
	for (list<Vertex*>::iterator i = listVertexes->begin(); i != listVertexes->end(); i++) {
		count++;
	}
	return count;
}

bool EulerWay::checkForEulerPath(EulerWay & graph)
{
	int count = 0;
	/* ������ ��������, ��� ���-�� ������ � �������� ������� ������ ���� �� ������ 2 */
	for (auto i : *vertexes) {
		if (getCountVertexesTo(*i) % 2 == 1) {
			count++;
		}
	}
	if (count > 2) {
		return false;
	}
	/***********************************************/

	/* ���� ��������� ����������� � ������� ������ � �������  */
	for (auto i : *vertexes) {
		DFS(graph, *i);
		break;
	}

	/* ��������� ����������� ������ ���� 1 � ��� � ��� ������� ������ ���� � ������ ������� */
	for (auto i : *vertexes) {
		if (getCountVertexesTo(*i) > 0 && i->color == 'W') {
			return false;
		}
	}
	/**************************************************/
	return true;
}
void EulerWay::removeEdge(Vertex & vertexFrom, Vertex & vertexTo)
{
	list<Edge>::iterator i;
	for (i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertexFrom && i->to == &vertexTo) {
			break;
		}
	}
	edges->erase(i);
	for (i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertexTo && i->to == &vertexFrom) {
			break;
		}
	}
	edges->erase(i);
}



void EulerWay::DFS(EulerWay & graph, Vertex & vertex)
{
		vertex.color = 'G';									// ������ ������� "����������"
		list<Vertex*> * vertexList = getVertexList(vertex); // �������� ������ ��������� ��� ������� vertex
		vertex.distance = time;	// ��������� ����� ��������� � �������
		for (auto i : *vertexList) {
			/* ������� �� ���� ���� ��������  */

			if (i->color == 'W') {
				/* ������� ��� �� ���� �������� */
				DFS(graph, *i);
			}
		}
		/* � ������� ��� ������������ ������, ������� ��� �� �������� */
		vertex.color = 'B';			// ������ � �����������
		vertex.finish = time;		// ����������� ����� ��������� �������
}
