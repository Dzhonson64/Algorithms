
#include "pch.h"
#include "DFS.h"
#include <list>
#include "string"
DFS::DFS()
{
	start = NULL;
	vertexes = new list<Vertex*>;
	order = new list<Vertex*>;
	edges = new std::list<Edge>;
	
}


DFS::~DFS()
{
}
void DFS::DFS_algoritm(DFS & graph)
{
	/* инициализируем время и номер компоненты */
	time = 0;
	col = 1;
	/* Пробегаемся первым DFS по графу, вычисляя время окончания вершин и заполения спика вершин, отсортированного в порядке убывания времени окончание */
	for (auto i : *vertexes) {
		
		if (i->color == 'W') {
			DFS_visit(graph, *i);
		}
	}
	/* Пробегаемся по созданному и заполенному списку и использвем второй DFS*/
	for (std::list<Vertex*>::iterator i = order->begin(); i != order->end(); i++) {

		if (!components[(*i)->str]) {
			/* Вершина не относится ни к какой компоненте */
			DFS_visit_2(graph, **i);
			col++;	// уже нашли компоненту связанности, поэтому увеличиваем номер компоненты для следующей
		}
	}
	
	
}

void DFS::DFS_visit(DFS & graph, Vertex & vertex)
{
	vertex.color = 'G';									// делаем вершину "посещённой"
	list<Vertex*> * vertexList = getVertexList(vertex); // получаем список смежности для вершины vertex
	time++;	// увеличиваем время 
	vertex.distance = time;	// запомнаем время вохожения в вершину
	for (auto i : *vertexList) {
		/* Прохоим по всем этим вершинам  */
		
		if (i->color == 'W') {
			/* Вершина ещё не была посещена */
			DFS_visit(graph, *i);
		}
	}
	/* У вершины нет непосещённых вершин, которые ещё не посещали */
	order->push_front(&vertex); // добавляем в начало списка вершину
	vertex.color = 'B';			// делаем её завершённой
	time++;						
	vertex.finish = time;		// запомминаем время окончания вершины
	
	
}

void DFS::DFS_visit_2(DFS & graph, Vertex & vertex)
{
	components[vertex.str] = col;	// устанавливаем номер компоненты для вершины
	list<Vertex*> * vertexList = getReverseVertexList(vertex); // получаем транспонированный список смежности для вершины vertex
	for (auto i : *vertexList) {
		/* Прохоим по всем этим вершинам  */

		if (!components[i->str]) {
			/* Вершина не входит ни в какую компоненту */
			DFS_visit_2(graph, *i);
		}
	}
}

void DFS::addVertex(Vertex & v)
{
	vertexes->push_back(&v);
}

void DFS::addEdge(Vertex & from, Vertex & to, bool oriented)
{
	Edge newEdge = Edge(from, to); 
	edges->push_back(newEdge);		
	if (oriented == false) {
		
		Edge newEdge_2 = Edge(to, from);
		edges->push_back(newEdge_2);
	}


}

list<Vertex*> * DFS::getVertexList(Vertex & vertex)
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
list<Vertex*> * DFS::getReverseVertexList(Vertex & vertex)
{
	list<Vertex*> * result = new list<Vertex*>;
	for (list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		if (i->to == &vertex) {
			/* Входящая вершина у ребра - это данная вершина */
			result->push_back(i->from);	// запоманием вершину, откуда это ребро идёт
		}
	}
	return result;
}

void DFS::showComponentVertexes()
{
	for (map<string, int>::iterator i = components.begin(); i != components.end(); i++) {
		cout << i->first << " - " << i->second << endl;
	}
}
