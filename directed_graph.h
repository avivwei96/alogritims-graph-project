#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH
#include "graph.h"

class directedGraph : public graph
{
	vector<int> in_degree;
	vector<int> out_degree;
public:
	directedGraph(int amount_of_ver, int amount_of_arcs);
	virtual void add_arc(int num_ver_out, int num_of_ver_in);
	virtual list<int> find_circuit(int num_of_ver);
	

private:

};

#endif // !DIRECTED_GRAPH

