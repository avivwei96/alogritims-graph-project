#ifndef UN_DIRECTED_GRAPH
#include "graph.h"
#include "Exceptions.h"
class un_directedGraph : public graph
{
	vector<int> degree;

public:
	un_directedGraph(int amount_of_ver, int amount_of_arcs);
	virtual void			init();
	virtual void			add_arc(int num_ver_out, int num_of_ver_in);
	virtual bool			is_euler_graph();
	virtual void			mark(list<arc>::iterator curr_arc);
	bool					is_even();
	void					same_arc(int num_ver1, int num_ver2);
	bool					is_connected();

};
#endif // !UN_DIRECTED_GRAPH
