#include "graph.h"

graph::graph(int amount_of_ver, int amount_of_arcs) : amount_of_ver(amount_of_ver), amount_of_arcs(amount_of_arcs)
{
	// this is a c'tor function 
	// the function create new graph and initialize it
	my_ver.reserve(amount_of_ver);
	for (int i = 1; i <= amount_of_ver; i++)
	{
		vertex new_ver(i);
		my_ver.push_back(new_ver);
	}
}
