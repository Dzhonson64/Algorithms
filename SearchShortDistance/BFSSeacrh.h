#pragma once
#include "Vertex.h"
#include "Graph.h"
#include "Edge.h"
#include <queue>
#include <list>
class BFSSeacrh : public Graph
{
private:
	std::queue<Vertex*>* penddingVertexses;
public:
	BFSSeacrh() : Graph() { 
		penddingVertexses = new std::queue<Vertex*>;
	};
	void BFS(Graph& graph, Vertex& vert, Vertex& vertFinding);
	void showPath(Vertex& finishVertex, bool stringData = false);	// вывод вершин в виде списка вершин, из которых состоит путь
	~BFSSeacrh();
};

