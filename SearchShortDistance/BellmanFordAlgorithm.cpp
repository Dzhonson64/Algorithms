#include "BellmanFordAlgorithm.h"




BellmanFordAlgorithm::~BellmanFordAlgorithm()
{
}

bool BellmanFordAlgorithm::BellmanFord(BellmanFordAlgorithm& graph, Vertex& vertex, Vertex& finishVertex)
{
	initGraph(graph, vertex); // �������������� �������� ��������� �� ������

	for (int i = 0; i < vertexes->size() - 1; i++) {
		for (auto j : *edges) {
			/* � ������ ������� ��� ���� ��� ���� ������ "����������" (��������� ����� ����������� ��������� �� �������) */
			relax(*j.to, *j.from, j.weight);
		}
	}
	/* ����� �������������� ����� � ����� */
	for (auto i : *edges) {
		if (i.to->distance > i.from->distance + i.weight) {
			/* 
				�������� ����� ����� ����������� ��������� �� �������, � �.�. � ��� �� V-1 ��� ��� ������ ���� �� ���������,
				������ ���� �����. ����, ������� �������� ��������� �� �������
			*/
			std::cout << "The graph has negative circle" << std::endl;
			return false;
		}
	}
	showPath(finishVertex, true); // ����� ������, �� ������� �������� ����������� ����
	return true;
}
void BellmanFordAlgorithm::showPath(Vertex& finitshVertex, bool showStr)
{

	Vertex* tempMover = finitshVertex.predecessor; // ���������� ������, ������� ������ � ����������� ����
	if (!tempMover) {
		/* ��� �� ���������� */
		std::cout << "No path!" << std::endl;
	}
	else {
		/* �� ���������� */
		std::list <Vertex> path; // ������, �������� ������� ������������ ���� � ���������� ������� (�����-�������)
		if (&finitshVertex) {
			// �������� ������� ����, �� ������� � ������ ������
			path.push_front(finitshVertex.str);
		}
		if (showStr) {
			/* и��� ������ ������ */
			while (tempMover) {
				/* ���� � ������� ���� ������, ������� ��� ��� � ������ � ����������� ���� */
				path.push_front(tempMover->str);
				tempMover = tempMover->predecessor;
			}
			/* ������� ������� ������������ ����*/
			for (auto i : path) {
				std::cout << i.str << ", ";
			}
		}
		else {
			/* и��� ������ ����� (���� �����, ������ ��������� � ����� � ������ �������� ) */
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