// Strongly_connected_components.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "DFS.h"

int main()
{

	/*
		РАЗЛОЖЕНИЕ ГРАФА НА СИЛЬНО СВЯЗАННЫЕ КОМПОНЕНТЫ

		Две вершины v и u называются "связанными", если существуют цепь с концами v и u. А граф называется "связным", если любая пара вершин связана.
		В ориентированный граф называется связным, если для любых двух его вершин v и u вершина u достижима из вершины v или вершина v достижима из вершины u.
		Таким образом непересекающиеся связные подграфы данного графа,  называются "компонентами связности" или просто "компонентой" графа.
		Сильно связанный граф - это граф, у которого есть путь между любой парой вершин (какую бы вершину мы не взяли, существует путь к нужной вершине, как в одном направлении, так и в обратном)
	
		Алгоритм:
			- Вызываем DFS для вычисления времени завершения каждой вершины графа, и сохранем в начало списка каждую вершину, после того как она стала чёрной. 
			  Таким образом, получается список, у которого время завершения вершин расположены в убыванющем порядке.
			- Проходимся по ново-созданному списку вершин и вызываем второй раз DFS, но он немного отличается от первого DFS. А именно, теперь мы ищем соединённые вершины с данной, транспонировав (перевернув) его рёбра.
			  И уже по транспонированным рёбрам мы перемещаемся для поиска компонента связанности.

			Транспонирование как раз помогает найти компоненты связности, т.к. мы проходимся уже по обратному пути, что и соответствует определению компоненты связанности.
	
	*/		
	DFS dfsGraph;

	/* Создание вершин */
	Vertex & a = *new Vertex("a");
	Vertex & b = *new Vertex("b");
	Vertex & c = *new Vertex("c");
	Vertex & d = *new Vertex("d");
	Vertex & e = *new Vertex("e");
	Vertex & f = *new Vertex("f");
	Vertex & g = *new Vertex("g");
	Vertex & h = *new Vertex("h");

	/* Добавления вершин в общий список */
	dfsGraph.addVertex(a);
	dfsGraph.addVertex(b);
	dfsGraph.addVertex(c);
	dfsGraph.addVertex(d);
	dfsGraph.addVertex(e);
	dfsGraph.addVertex(f);
	dfsGraph.addVertex(g);
	dfsGraph.addVertex(h);

	/* Установление связей (рёбер) между вершинами */
	dfsGraph.addEdge(a, b, true);
	dfsGraph.addEdge(b, c, true);
	dfsGraph.addEdge(b, f, true);
	dfsGraph.addEdge(b, e, true);
	dfsGraph.addEdge(c, d, true);
	dfsGraph.addEdge(c, g, true);
	dfsGraph.addEdge(d, c, true);
	dfsGraph.addEdge(d, h, true);
	dfsGraph.addEdge(e, a, true);
	dfsGraph.addEdge(e, f, true);
	dfsGraph.addEdge(f, g, true);
	dfsGraph.addEdge(g, f, true);
	dfsGraph.addEdge(g, h, true);


	dfsGraph.DFS_algoritm(dfsGraph);
	dfsGraph.showComponentVertexes();
}