#include "Dijksrta.h"





Vertex* Dijksrta::getMinVertex()
{
	Vertex * temp = considerVertexes->front();	// ������� � ���. distance
	std::list<Vertex*>::iterator & item = *&considerVertexes->begin();	// ��������, �������� �������� (������� � ����������), ������� ����� ����� ����� �������
	for (std::list<Vertex*>::iterator & i = *&considerVertexes->begin(); i != *&considerVertexes->end(); i++) { 
		if ((*i)->distance < temp->distance) {
			temp = *i;
			item = i;
		}
	}
	considerVertexes->erase(item); // �������� ������� �� ������ ��������������� ������
	return temp;
}

Dijksrta::~Dijksrta()
{
	
}

void Dijksrta::DijksrtaAlgorithm(Dijksrta & graph, Vertex & startVertex, bool stringData)
{
	/* �������������� ���������� */
	//numbersVertexes = new std::vector <Vertex*>;
	considerVertexes = new std::list<Vertex*>;

	/* ������� ��� ������� � ������ ��������������� */
	for (auto & i: *vertexes) {
		considerVertexes->push_back(i);
	}

	initGraph(graph, startVertex); // �������������� ���������� �� ������	

	while (!considerVertexes->empty()) {
		/* ��������������� ������� �� ����������� */
		Vertex* temp = getMinVertex(); // ���� ������� � ����������� �����������
		//numbersVertexes->push_back(temp);

		std::list <Vertex*>* vertexesList = getVertexList(*temp); // ������ ������� ������
		/* ������ ���������� ��� ���� ������� ������ */
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

