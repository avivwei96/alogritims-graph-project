#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH
#include "graph.h"
#include <list>
#include <iostream>
using namespace std;

class directedGraph : public graph
{
	vector<int> in_degree;
	vector<int> out_degree;
public:
	directedGraph(int amount_of_ver, int amount_of_arcs);
	virtual void add_arc(int num_ver_out, int num_of_ver_in);
	virtual list<vertex*> find_circuit(int num_of_ver);
	list<vertex*> find_euler();
	bool is_euler_graph();
	bool is_strongly_connected();
	void visit(vertex* ver);
};

#endif // !DIRECTED_GRAPH

