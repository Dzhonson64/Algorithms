#pragma once
#include "Vertex.h"
#include "Graph.h"
#include <functional>
#include <queue>
#include <vector>
#include <list>


/*
	Ќахождени€ кратчайших путей от одной вершины до всех остальных в ориентированном взвешенном графе,
	при условии, что все ребра в графе имеют неотрицательные веса.
*/






class Dijksrta : public Graph
{
private:
	std::list<Vertex*> * considerVertexes = NULL; /* вершин, которые рассматриваютс€ во врем€ алгоритмы
													(первоначально их кол-во индентично списку вершин и постепенно будут уменьшатьс€ к 0).
													!!!¬ идеале должен не список, а двоична€ куча (очередь с приоритетом)!!!
												*/
	//std::vector <Vertex*> * numbersVertexes = NULL;
	Vertex* getMinVertex();	// “.к. € не использовал двоичную кучу, то пришлось самим реализовать поиск вершины с мин. distance
public:
	Dijksrta() :Graph()
	{
	};
	~Dijksrta();
	void DijksrtaAlgorithm(Dijksrta & graph, Vertex & startVertex, bool stringData = false);	// основной алгоритм ƒейкстра
	void showPath(Vertex& finishVertex, bool stringData = false);	// вывод вершин в виде списка вершин, из которых состоит путь
	
};



