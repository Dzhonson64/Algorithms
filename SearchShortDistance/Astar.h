#pragma once

#include "Graph.h"

/* 
	Алгоритм A* самый оптимальный из всех 3-х алгоритмов, но он не на всех графах работате. Возможно, есть предположение, A* гарантированно найдёт кратчайший путь,
	если эвристика никогда не больше истинного расстояния. Когда эвристика становится меньше, A* превращается в алгоритм Дейкстры.
	Когда эвристика становится больше, A* превращается в жадный поиск по наилучшему первому совпадению.
*/
class Astar : public Graph
{
private:
	std::list<Vertex*>* opened = NULL; /* вершин, которые рассматриваются во время алгоритмы
													(первоначально их кол-во индентично списку вершин и постепенно будут уменьшаться к 0).
													!!!В идеале должен не список, а двоичная куча (очередь с приоритетом)!!!
											*/
	std::list<Vertex*>* closed = NULL;	// рассмотренные вершины
	Vertex* getMinVertex();	// Т.к. я не использовал двоичную кучу, то пришлось самим реализовать поиск вершины с мин. distance
public:
	Astar() :Graph()
	{
	};
	void AstarAlgorithm(Astar& graph, Vertex& startVertex, Vertex& finishVertex, bool stringData = false);	// основной алгоритм Дейкстра
	void showPath(Vertex& finishVertex, bool stringData = false);	// вывод вершин в виде списка вершин, из которых состоит путь
	bool isOpened(Vertex& vertex);
	bool isClosed(Vertex& vertex);
	std::list<Vertex*>* getVertexList(Vertex & vertex);
};


