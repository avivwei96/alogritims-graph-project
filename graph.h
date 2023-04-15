#ifndef GRAPH
#define GRAPH
#include <iostream>
#include<vector>
#include<list>
#include"vertex.h"

class graph
{
protected:
	int amount_of_ver;
	int amount_of_arcs;
	vector<vertex> my_ver;
public:
	graph(int amount_of_ver, int amount_of_arcs);
	virtual void add_arc(int num_ver_out, int num_of_ver_in) = 0;
	virtual list<int> find_circuit(int num_of_ver) = 0;

};

#endif // !GRAPH