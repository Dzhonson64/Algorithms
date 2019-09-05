#include "BellmanFordAlgorithm.h"




BellmanFordAlgorithm::~BellmanFordAlgorithm()
{
}

bool BellmanFordAlgorithm::BellmanFord(BellmanFordAlgorithm& graph, Vertex& vertex, Vertex& finishVertex)
{
	initGraph(graph, vertex); // инициализируем значения дистанций до вершин

	for (int i = 0; i < vertexes->size() - 1; i++) {
		for (auto j : *edges) {
			/* В каждой вершине для всех его рёбер делаем "релаксацию" (вычисляем более оптимальную дистанцию до вершины) */
			relax(*j.to, *j.from, j.weight);
		}
	}
	/* Поиск отрицательного цикла в графе */
	for (auto i : *edges) {
		if (i.to->distance > i.from->distance + i.weight) {
			/* 
				Алгоритм нашёл более оптимальную дистанцию до вершины, а т.к. у нас за V-1 шаг уже должно быть всё нормально,
				значит есть отриц. цикл, который уменьшил дистанцию до вершины
			*/
			std::cout << "The graph has negative circle" << std::endl;
			return false;
		}
	}
	showPath(finishVertex, true); // вывод вершин, по которым проходит оптимальный путь
	return true;
}
void BellmanFordAlgorithm::showPath(Vertex& finitshVertex, bool showStr)
{

	Vertex* tempMover = finitshVertex.predecessor; // запоминаем предка, который входит в оптимальный путь
	if (!tempMover) {
		/* Его не существует */
		std::cout << "No path!" << std::endl;
	}
	else {
		/* Он существует */
		std::list <Vertex> path; // список, хранящий вершины оптимального путь в правильном порядке (слева-направо)
		if (&finitshVertex) {
			// конечная вершина есть, то заносим в голову списка
			path.push_front(finitshVertex.str);
		}
		if (showStr) {
			/* Рёбра хранят строки */
			while (tempMover) {
				/* Пока у вершины есть предок, который как раз и входит в оптимальный путь */
				path.push_front(tempMover->str);
				tempMover = tempMover->predecessor;
			}
			/* Выводим вершины оптимального пути*/
			for (auto i : path) {
				std::cout << i.str << ", ";
			}
		}
		else {
			/* Рёбра хранят числа (тоже самое, только добавляем и выдим в список значения ) */
			while (tempMover) {
				path.push_front(tempMover->number);
				tempMover = tempMover->predecessor;
			}
			for (auto i : path) {
				std::cout << i.number << ", ";
			}
		}

	}
}