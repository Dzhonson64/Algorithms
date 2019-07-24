// TopologicalSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "DFS.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	DFS dfsGraph;

	/* Создание вершин */
	Vertex & v1 = *new Vertex("Трусы");
	Vertex & v2 = *new Vertex("Брюки");
	Vertex & v3 = *new Vertex("Ремень");
	Vertex & v4 = *new Vertex("Пиджак");
	Vertex & v5 = *new Vertex("Туфли");
	Vertex & v6 = *new Vertex("Носки");
	Vertex & v7 = *new Vertex("Рубашка");
	Vertex & v8 = *new Vertex("Галстук");
	Vertex & v9 = *new Vertex("Часы");

	/* Добавления вершин в общий список */
	dfsGraph.addVertex(v1);
	dfsGraph.addVertex(v2);
	dfsGraph.addVertex(v3);
	dfsGraph.addVertex(v4);
	dfsGraph.addVertex(v5);
	dfsGraph.addVertex(v6);
	dfsGraph.addVertex(v7);
	dfsGraph.addVertex(v8);
	dfsGraph.addVertex(v9);

	/* Установление связей (рёбер) между вершинами */
	dfsGraph.addEdge(v1, v2, true);
	dfsGraph.addEdge(v1, v5, true);
	dfsGraph.addEdge(v2, v3, true);
	dfsGraph.addEdge(v2, v5, true);
	dfsGraph.addEdge(v3, v4, true);
	dfsGraph.addEdge(v6, v5, true);
	dfsGraph.addEdge(v7, v3, true);
	dfsGraph.addEdge(v7, v8, true);
	
	
	dfsGraph.DFS_algoritm(dfsGraph);

	/* Выводим вершины в топологическом порядке. В скобках указано время завершения работы с вершиной, относительно чего совершалсь сортировка */
	for (auto i : *dfsGraph.vertexesSort) {
		std::cout << i->str << " (" << i->finish << ") " << std::endl;
	}
	
}