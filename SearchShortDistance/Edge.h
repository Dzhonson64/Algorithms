#pragma once
#include "Vertex.h"
class Edge
{
public:
	Edge();
	Edge(Vertex& from, Vertex& to);
	Edge(Vertex& from, Vertex& to, int weight);
	~Edge();
	Vertex* from;
	Vertex* to;
	int weight;
};

