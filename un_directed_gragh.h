#ifndef UN_DIRECTED_GRAPH
#include "graph.h"
class un_directedGraph : public graph
{
	vector<int> degree;

public:
	bool is_even();
	un_directedGraph(int amount_of_ver, int amount_of_arcs);
	void init_undeircted_graph();
	void same_arc(int num_ver1, int num_ver2);
	void mark(list<arc>::iterator curr_arc);
	list<arc>::iterator next_avilable(int num_ver);
	virtual void add_arc(int num_ver_out, int num_of_ver_in);
	virtual list<vertex*> find_circuit(int num_of_ver);
	list<vertex*> find_euler_circuit();
	void visit(vector<vertex>::iterator curr_ver);
	bool is_connected();
	bool is_eulerian();


};
#endif // !UN_DIRECTED_GRAPH
