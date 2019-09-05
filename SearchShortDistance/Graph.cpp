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
	Edge newEdge = Edge(from, to, weight); // создаём ребро из двух вершин: из какой вершины выходит ребро и в какую вершину
	edges->push_back(newEdge);		// добавляем в список рёбер
	if (oriented == false) {
		/* Граф неориетиованный => делаем тоже самое, но меняем местами вершины */
		Edge newEdge_2 = Edge(to, from, weight);
		edges->push_back(newEdge_2);
		
	}

}
void Graph::addEdge(Vertex& from, Vertex& to, bool oriented)
{
	Edge newEdge = Edge(from, to); // создаём ребро из двух вершин: из какой вершины выходит ребро и в какую вершину
	edges->push_back(newEdge);		// добавляем в список рёбер
	if (oriented == false) {
		/* Граф неориетиованный => делаем тоже самое, но меняем местами вершины */
		Edge newEdge_2 = Edge(to, from);
		edges->push_back(newEdge_2);
	}


}

std::list<Vertex*>* Graph::getVertexList(Vertex& vertex)
{
	std::list<Vertex*>* result = new std::list<Vertex*>; // результирующий список смежности для вершины vertex
	for (std::list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertex) {
			/* В списке рёбер есть вершина vertex, которая указывает вершину, из которой ВЫХОДИТ ребро*/
			result->push_back(i->to); // но в список смежности добавляем вершину, в которой ВХОДИТ ребро
		}
	}
	return result;
}

void Graph::relax(Vertex& to, Vertex& from, int weight)
{
	if (to.distance > from.distance + weight) {
		/* Дистанция от начальной вершины (from) + вес ребра меньше старой дистанции вершины (to) */
		to.distance = from.distance + weight; // обновляем на более оптимальное расстояние
		to.predecessor = &from; // обновляем предка (относительно него выводится оптимальный путь)
	}
}

void Graph::initGraph(Graph& graph, Vertex& start)
{
	for (auto i : *vertexes) {
		// всем вершинам присваиваем начальное макс. расстояние
		i->distance = INF;
		i->distanceF = INF;
	}
	start.distance = 0; // начальной вершине присваем 0, т.к. расстояние от начальной до начальной вершины есть 0
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
