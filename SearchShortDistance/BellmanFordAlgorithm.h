#pragma once
#include "Vertex.h"
#include "Graph.h"


/*  
	Алгоритм Форда - Беллмана позволяет найти кратчайшие пути из одной вершины графа до всех остальных, даже для графов,
	в которых веса ребер могут быть отрицательными.Тем не менее, в графе не должно быть циклов отрицательного веса (циклы, где общая сумма расстояние будет отрицательна), достижимых из начальной вершины,
	иначе вопрос о кратчайших путях является бессмысленным.При этом алгоритм Форда - Беллмана позволяет определить наличие циклов отрицательного веса,
	достижимых из начальной вершины.
*/


class BellmanFordAlgorithm : public Graph
{
public:
	BellmanFordAlgorithm() : Graph() {}; 
	~BellmanFordAlgorithm();
	bool BellmanFord(BellmanFordAlgorithm& graph, Vertex& vertex, Vertex& finishVertex);
	void showPath(Vertex& finitshVertex, bool showStr = false);	// вывод оптимального пути (вершин)
};

