#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <queue>
#include <list>
#include <vector>
class Graph
{
protected:
	const unsigned long int INF = 4294967295;	// число, котором инициализируются все дистации вершин графа (типо бесконечность)
	int time;
	std::list<Vertex*>* vertexes;						// список всех вершин
	std::list<Edge>* edges;								// список рёбер
public:
	Graph();
	~Graph();
	void addVertex(Vertex& v);
	void addVertex(Vertex& v, int posX, int posY);						// добавление вершины
	void addEdge(Vertex& from, Vertex& to, bool oriented = false); // добавление ребра (oriented = false - граф неориентированный, oriented = true - ориентированный)
	void addEdge(Vertex& from, Vertex& to, int weight = 0, bool oriented = false); // добавление ребра (oriented = false - граф неориентированный, oriented = true - ориентированный)
	std::list<Vertex*>* getVertexList(Vertex& vertex);	// получение списка смежности для вершины vertex
	void relax(Vertex& to, Vertex& from, int weight);	// релаксация вершины - обновления дистанции до вершины "to" на более оптимальную
	void initGraph(Graph& graph, Vertex& start);		// инициализация дистанция до вершин, где старновая вершина - "start"	
	int getEdgeWeght(Vertex& from, Vertex& to);			// получение веса ребра
	double heuristic(Vertex & current, Vertex & finish);
};

