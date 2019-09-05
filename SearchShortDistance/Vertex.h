#pragma once
#include <iostream>
class Vertex
{
public:
	Vertex();
	Vertex(int number);
	Vertex(std::string str);
	~Vertex();
	long long distance;
	double distanceF;
	int finish;
	char color;
	int number;
	std::string str;
	Vertex* predecessor;
	bool visited = false;
	int x;
	int y;
};
