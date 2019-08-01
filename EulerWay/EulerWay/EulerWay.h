#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <stack> 
#include <list>
#include <map>
using namespace std;
class EulerWay
{
private:
	Vertex * start;
	int time;	// время прохождения графа, отоносительно него узнаются время вхождения в вершину и его окончание
	int col;	// номер компоненты связанности
public:
	EulerWay();
	~EulerWay();
	void findEulerPath(Vertex & vertex);			// алгоритма поиска эйлерового пути
	list<Vertex*> * vertexes;						// список вершин графа
	stack<Vertex*> * st;							// стек вершин, которых хранит пройденные вершины
	list<Edge> * edges;								// список рёбер
	void addVertex(Vertex & v);						// добавление новой вершины
	void addEdge(Vertex & from, Vertex & to, bool oriented = false); // добавление нового ребра (oriented = false - граф неориетированный, oriented = true - оринетированный)
	list<Vertex*>* getVertexList(Vertex & vertex);	// получение списка смежности для вершины vertex
	int getCountVertexesTo(Vertex & v);				// получение степени вершины
	bool checkForEulerPath(EulerWay & graph);		// проверка на присутствие эйлерового пути/цикла
	void removeEdge(Vertex & vertexFrom, Vertex & vertexTo);	// удаление ребра
	void eulerPath(EulerWay & graph);							// обёрточная ф-ия для алгоритма поиска эйлерового пути
	void DFS(EulerWay & graph, Vertex & vertex);				// обход в глубину
};