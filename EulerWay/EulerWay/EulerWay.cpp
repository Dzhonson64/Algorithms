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
		/* Эйлеровый путь существует */
		findEulerPath(*vertexes->front());
	}
	else {
		/* Эйлеровый путь не существует */
		std::cout << "This graph don't have euler way" << std::endl;
	}
}
void EulerWay::findEulerPath(Vertex & vertex)
{
	st->push(&vertex);
	while (!st->empty()) {
		/* Стек не пустой */

		Vertex * v = st->top(); // берём вершину с вершины стека
		list<Vertex*> * vertexList = getVertexList(*v);	// находим смежные вершины
		for (auto i : *vertexList) {
			st->push(i);	// кладём в стек первую попавшуюся вершину из смежных
			removeEdge(*v, *i);	// удаляем ребро между рассматриваемой вершиной и её смежной
			break;
		}
		if (v == st->top()) {
			/* Степень вершины равна 0, т.е. смежных вершин было 0 и ничего до того в стек не добавлялось */
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
			/* Выходящая вершина у ребра - это данная вершина */
			result->push_back(i->to); // запоманием вершину, куда это ребро идёт
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
	/* Делаем проверку, что кол-во вершин с нечётной степени должно быть не больше 2 */
	for (auto i : *vertexes) {
		if (getCountVertexesTo(*i) % 2 == 1) {
			count++;
		}
	}
	if (count > 2) {
		return false;
	}
	/***********************************************/

	/* Ищем компонент связанности с помощью поиска в глубину  */
	for (auto i : *vertexes) {
		DFS(graph, *i);
		break;
	}

	/* Компонент связанности должна быть 1 и все в ней вершины должны быть с чётной степени */
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
		vertex.color = 'G';									// делаем вершину "посещённой"
		list<Vertex*> * vertexList = getVertexList(vertex); // получаем список смежности для вершины vertex
		vertex.distance = time;	// запомнаем время вохожения в вершину
		for (auto i : *vertexList) {
			/* Прохоим по всем этим вершинам  */

			if (i->color == 'W') {
				/* Вершина ещё не была посещена */
				DFS(graph, *i);
			}
		}
		/* У вершины нет непосещённых вершин, которые ещё не посещали */
		vertex.color = 'B';			// делаем её завершённой
		vertex.finish = time;		// запомминаем время окончания вершины
}
