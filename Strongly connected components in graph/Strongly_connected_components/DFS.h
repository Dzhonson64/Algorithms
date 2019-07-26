#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <queue> 
#include <list>
#include <map>
using namespace std;
class DFS
{
private:
	Vertex * start;
	int time;	// время прохождения графа, отоносительно него узнаются время вхождения в вершину и его окончание
	int col;	// номер компоненты связанности
public:
	DFS();
	~DFS();
	void DFS_algoritm(DFS & graph); // общий метод, содержащий два DFS
	void DFS_visit(DFS & graph, Vertex & vertex); // DFS, который обходит граф первым для вычисления времени окончания для вершины
	void DFS_visit_2(DFS & graph, Vertex & vertex);	 // DFS, который обходит граф вторым поиска компонента связанности
	list<Vertex*> * vertexes;						// список вершин графа
	list<Vertex*> *	order;							// список вершин графа, которые отсортированны в порядке убывания времени окончания
	list<Edge> * edges;								// список рёбер
	map <string, int> components;					// массив (хеш), который хранит <название ребра, номер компоненты>
	void addVertex(Vertex & v);						// добавление новой вершины
	void addEdge(Vertex & from, Vertex & to, bool oriented = false); // добавление нового ребра (oriented = false - граф неориетированный, oriented = true - оринетированный)
	list<Vertex*>* getVertexList(Vertex & vertex);	// получение списка смежности для вершины vertex
	list<Vertex*>* getReverseVertexList(Vertex & vertex);	// получение транспонированного списка смежности для вершины vertex
	void showComponentVertexes();					// вывод всех вершин с их соответствующими номерами связанности
};

