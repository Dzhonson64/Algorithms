#include "Edge.h"


Edge::Edge() :from(NULL), to(NULL), weight(0)
{
}

Edge::Edge(Vertex& from, Vertex& to) :from(&from), to(&to), weight(0)
{
}
Edge::Edge(Vertex& from, Vertex& to, int weight) : from(&from), to(&to), weight(weight)
{
}

Edge::~Edge()
{
}