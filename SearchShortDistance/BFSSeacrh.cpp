#include "BFSSeacrh.h"



void BFSSeacrh::BFS(Graph& graph, Vertex& vert, Vertex& finishVertex)
{
	vert.color = 'G';
	vert.distance = 0;
	vert.predecessor = NULL;
	penddingVertexses->push(&vert);
	while (!penddingVertexses->empty()) {
		Vertex* temp = penddingVertexses->front();
		std::list<Vertex*>* vertexList = getVertexList(*temp);
		penddingVertexses->pop();
		for (auto i : *vertexList) {
			if (i->color == 'W') {
				i->color = 'G';
				penddingVertexses->push(i);
				i->distance = temp->distance++;
				i->predecessor = temp;
			}
		}
		temp->color = 'B';
	}


	showPath(finishVertex);

}

void BFSSeacrh::showPath(Vertex& finishVertex, bool stringData)
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


BFSSeacrh::~BFSSeacrh()
{
}