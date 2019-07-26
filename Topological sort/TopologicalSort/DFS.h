#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <queue> 
#include <list>
using namespace std;
class DFS
{
private:
	Vertex * start;
	int time;	// время входа и окончание рассмотрения вершины 
public:
	DFS();
	~DFS();
	void DFS_algoritm(DFS & graph); // обход в глубину
	void DFS_visit(DFS & graph, Vertex & vertex); // обход в глубину
	//queue<Vertex*> * pendingVertexes;				// очередь вершин для дальнейшего их рассмотрения !!! Должен тогда использоваться СТЕК !!!
	list<Vertex*> * vertexes;						// список всех вершин
	list<Vertex*>*vertexesSort;						// отсортированный топологически вершины графа
	list<Edge> * edges;								// список рёбер
	void addVertex(Vertex & v);						// добавление вершины
	void addEdge(Vertex & from, Vertex & to, bool oriented = false); // добавление ребра (oriented = false - граф неориентированный, oriented = true - ориентированный)
	list<Vertex*>* getVertexList(Vertex & vertex);	// получение списка смежности для вершины vertex
};
