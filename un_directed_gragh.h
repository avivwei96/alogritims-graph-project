#ifndef UN_DIRECTED_GRAPH
#include "graph.h"
class un_directedGraph : public graph
{
	vector<int> degree;

public:
	un_directedGraph(int amount_of_ver, int amount_of_arcs);
	void same_arc(int num_ver1, int num_ver2);
	void mark(int num_ver1, int num_ver2);
	vector<vertex>::iterator next_avilable(int num_ver);
	virtual void add_arc(int num_ver_out, int num_of_ver_in);
	virtual list<int> find_circuit(int num_of_ver);
	list<int> find_euler_circuit();
};
#endif // !UN_DIRECTED_GRAPH
