#include "Astar.h"

Vertex* Astar::getMinVertex()
{
	Vertex* temp = opened->front();	// вершина с мин. distance
	std::list<Vertex*>::iterator& item = *&opened->begin();	// итератор, хранящий итератор (позицию в контейнере), которую нужно потом будет удалить
	for (std::list<Vertex*>::iterator& i = *&opened->begin(); i != *&opened->end(); i++) {
		if ((*i)->distanceF < temp->distanceF) {
			temp = *i;
			item = i;
		}
	}
	opened->erase(item); // удалаяем вершину из списка рассматриваемых вершин
	return temp;
}

void Astar::AstarAlgorithm(Astar& graph, Vertex& startVertex, Vertex& finishVertex, bool stringData)
{
	opened = new std::list<Vertex*>; // множество частных решений
	closed = new std::list<Vertex*>; // множество уже пройденных вершин
	
	startVertex.distanceF = startVertex.distance + heuristic(startVertex, finishVertex); // вычисчляем эвристическое расстояние 

	opened->push_back(&startVertex);

	initGraph(graph, startVertex); // инициализируем расстояния до вершин

	while (!opened->empty()) {
		/* Рассматриваемые вершины не закончились */
		Vertex* current = getMinVertex(); // берём вершину с минимальным расстоянием
		closed->push_back(current);
		if (current == &finishVertex) {
			return;
		}

		std::list <Vertex*>* vertexesList = getVertexList(*current); // список смежных вершин
		for (auto &next : *vertexesList) {
			if (isClosed(*next)) {
				continue;
			}
			double newCost = current->distance + getEdgeWeght(*current, *next); // вычисляем новую дистанцию
			if (newCost < next->distance) {
				/* Новая дистанция меньше старой */
				next->predecessor = current;
				next->distance = newCost;
				next->distanceF = next->distance + heuristic(*next, finishVertex);
				if (!isOpened(*next)) {
					opened->push_back(next);
				}
			}
		}
	}
	std::cout << "Error path" << std::endl;
}

bool Astar::isOpened(Vertex& vertex)
{
	for (auto &i: *opened) {
		if (i == &vertex) {
			return true;
		}
	}
	return false;
}
bool Astar::isClosed(Vertex& vertex)
{
	for (auto& i : *closed) {
		if (i == &vertex) {
			return true;
		}
	}
	return false;
}
std::list<Vertex*>* Astar::getVertexList(Vertex& vertex)
{
	std::list<Vertex*>* result = new std::list<Vertex*>; // результирующий список смежности для вершины vertex
	for (std::list<Edge>::iterator i = edges->begin(); i != edges->end(); i++) {
		
			if (i->from == &vertex) {
				for (auto& j : *closed) {
					if (i->to == j) {
						break;
					}
				}
				/* В списке рёбер есть вершина vertex, которая указывает вершину, из которой ВЫХОДИТ ребро*/
				result->push_back(i->to); // но в список смежности добавляем вершину, в которой ВХОДИТ ребро

			}
		
		
	}
	return result;
}
void Astar::showPath(Vertex& finishVertex, bool stringData)
{
	Vertex* tempPredeccor = &finishVertex;
	std::list<Vertex*>* order = new std::list<Vertex*>;
	order->push_front(tempPredeccor);
	while (tempPredeccor->predecessor) {

		order->push_front(tempPredeccor->predecessor);
		tempPredeccor = tempPredeccor->predecessor;
	}
	if (!stringData) {
		for (auto& i : *order) {
			std::cout << i->str << " -> ";
		}
	}
	else {
		for (auto& i : *order) {
			std::cout << i->number << " -> ";
		}
	}


}