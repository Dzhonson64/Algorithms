// EulerWay.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "EulerWay.h"

int main()
{
	/*
		Поиск Ейлерового пути или ейлерового цикла (работате для неоринтированного графа)
	*/
	EulerWay dfsGraph;

	Vertex & a = *new Vertex("a");
	Vertex & b = *new Vertex("b");
	Vertex & c = *new Vertex("c");
	Vertex & d = *new Vertex("d");
	Vertex & e = *new Vertex("e");

	/* Добавления вершин в общий список */
	dfsGraph.addVertex(a);
	dfsGraph.addVertex(b);
	dfsGraph.addVertex(c);
	dfsGraph.addVertex(d);
	dfsGraph.addVertex(e);

	/* Установление связей (рёбер) между вершинами */
	dfsGraph.addEdge(a, b);
	dfsGraph.addEdge(a, c);
	dfsGraph.addEdge(b, c);
	dfsGraph.addEdge(c, d);
	dfsGraph.addEdge(c, e);
	dfsGraph.addEdge(d, e);


	dfsGraph.eulerPath(dfsGraph);
}
