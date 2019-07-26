#include "pch.h"
#include "DFS.h"
#include <list>
DFS::DFS()
{
	start = NULL;
	vertexes = new list<Vertex*>;
	vertexesSort = new list<Vertex*>;
	edges = new std::list<Edge>;
	time = 0;
}


DFS::~DFS()
{
}
void DFS::DFS_algoritm(DFS & graph)
{
	time = 0;

	for (auto i : *vertexes) {
		/* Проходимся по всем вершинам графа */
		if (i->color == 'W') {
			/* Вершина белая => переходм к её исследованию */
			DFS_visit(graph, *i);
		}
	}
}

void DFS::DFS_visit(DFS & graph, Vertex & vertex)
{
	
	vertex.color = 'G';									// помечаем её, как иследоваемую
	list<Vertex*> * vertexList = getVertexList(vertex); // запоминаем список смежности для вершины vertex
	time++;
	vertex.distance = time;
	for (auto i : *vertexList) {
		/* Проходим по всем смежным вершинам */
		
		if (i->color == 'W') {

			
			/* Вершина неисследованная */
			i->predecessor = &vertex;	// запоминаем из какой вершины пришли
			
			DFS_visit(graph, *i);		// рассматриваем уже смежную вершину
		}
	}
	/* Все смежные вершины серые, то начинаем помечать уже исследованные вершины */
	vertex.color = 'B';
	time++;
	vertex.finish = time;
	vertexesSort->push_front(&vertex); // добавляем в список уже исследованную вершину (можно ипользовать и стек)
	
}

void DFS::addVertex(Vertex & v)
{
	vertexes->push_back(&v);
}

void DFS::addEdge(Vertex & from, Vertex & to, bool oriented)
{
	Edge newEdge = Edge(from, to); // создаём ребро из двух вершин: из какой вершины выходит ребро и в какую вершину
	edges->push_back(newEdge);		// добавляем в список рёбер
	if (oriented == false) {
		/* Граф неориетиованный => делаем тоже самое, но меняем местами вершины */
		Edge newEdge_2 = Edge(to, from);
		edges->push_back(newEdge_2);
	}


}

list<Vertex*> * DFS::getVertexList(Vertex & vertex)
{
	list<Vertex*> * result = new list<Vertex*>; // результирующий список смежности для вершины vertex
	for (list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		if (i->from == &vertex) {
			/* В списке рёбер есть вершина vertex, которая указывает вершину, из которой ВЫХОДИТ ребро*/
			result->push_back(i->to); // но в список смежности добавляем вершину, в которой ВХОДИТ ребро
		}
	}
	return result;
}
