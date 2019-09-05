#include <iostream>
#include "Graph.h"
#include "BFSSeacrh.h"
#include "BellmanFordAlgorithm.h"
#include "Dijksrta.h"
#include "Astar.h"
#include "Vertex.h"
#include "Edge.h"


int main()
{
	//Graph graph;
	//BFSSeacrh bfs;
	//BellmanFordAlgorithm bellFord;
	//Dijksrta dijksrta;
	Astar aStar;

	Vertex& s = *new Vertex("s");
	Vertex& t = *new Vertex("t");
	Vertex& x = *new Vertex("x");
	Vertex& y = *new Vertex("y");
	Vertex& z = *new Vertex("z");

	aStar.addVertex(s, 1, 5);
	aStar.addVertex(t, 3, 2);
	aStar.addVertex(x, 8, 2);
	aStar.addVertex(y, 3, 7);
	aStar.addVertex(z, 8, 7);

	aStar.addEdge(s, t, 100, true);
	aStar.addEdge(s, y, 50, true);
	aStar.addEdge(t, x, 10, true);
	aStar.addEdge(t, y, 20, true);
	aStar.addEdge(y, t, 30, true);
	aStar.addEdge(y, x, 90, true);
	aStar.addEdge(y, z, 20, true);
	aStar.addEdge(z, x, 60, true);
	aStar.addEdge(x, z, 40, true);
	aStar.addEdge(z, s, 70, true);

	//bellFord.BellmanFord(bellFord, s, z);
	//dijksrta.DijksrtaAlgorithm(dijksrta, s, true);
	//dijksrta.showPath(z);
	aStar.AstarAlgorithm(aStar, s, x, true);

}

