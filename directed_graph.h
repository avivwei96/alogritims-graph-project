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
	vertex* the_last_to_finish;
public:
	directedGraph(int amount_of_ver, int amount_of_arcs);
	void                  init();
	virtual void          add_arc(int num_ver_out, int num_of_ver_in);
	virtual void          mark(list<arc>::iterator curr_arc);
	virtual bool          is_euler_graph();
	bool                  is_strongly_connected();
	directedGraph         creat_transpose();	
};

#endif // !DIRECTED_GRAPH

