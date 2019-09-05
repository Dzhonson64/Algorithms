#include "Dijksrta.h"





Vertex* Dijksrta::getMinVertex()
{
	Vertex * temp = considerVertexes->front();	// вершина с мин. distance
	std::list<Vertex*>::iterator & item = *&considerVertexes->begin();	// итератор, хранящий итератор (позицию в контейнере), которую нужно потом будет удалить
	for (std::list<Vertex*>::iterator & i = *&considerVertexes->begin(); i != *&considerVertexes->end(); i++) { 
		if ((*i)->distance < temp->distance) {
			temp = *i;
			item = i;
		}
	}
	considerVertexes->erase(item); // удалаяем вершину из списка рассматриваемых вершин
	return temp;
}

Dijksrta::~Dijksrta()
{
	
}

void Dijksrta::DijksrtaAlgorithm(Dijksrta & graph, Vertex & startVertex, bool stringData)
{
	/* Инициализируем контейнеры */
	//numbersVertexes = new std::vector <Vertex*>;
	considerVertexes = new std::list<Vertex*>;

	/* Заносим все вершины в список рассматриваемых */
	for (auto & i: *vertexes) {
		considerVertexes->push_back(i);
	}

	initGraph(graph, startVertex); // инициализируем расстояния до вершин	

	while (!considerVertexes->empty()) {
		/* Рассматриваемые вершины не закончились */
		Vertex* temp = getMinVertex(); // берём вершину с минимальным расстоянием
		//numbersVertexes->push_back(temp);

		std::list <Vertex*>* vertexesList = getVertexList(*temp); // список смежных вершин
		/* Делаем релаксацию для всех смежных вершин */
		for (auto i : *vertexesList) {
			relax(*i, *temp, getEdgeWeght(*temp, *i));
		}
	}

}
void Dijksrta::showPath(Vertex& finishVertex, bool stringData)
{
	Vertex* tempPredeccor = &finishVertex;
	std::list<Vertex*> * order = new std::list<Vertex*>;
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

