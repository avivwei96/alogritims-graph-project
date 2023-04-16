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
	virtual void          init() = 0;
	virtual void          add_arc(int num_ver_out, int num_of_ver_in) = 0;
	virtual bool          is_euler_graph() = 0;
	virtual void          mark(list<arc>::iterator curr_arc) = 0;
	 list<vertex*>		  find_circuit(int num_of_ver);
	list<vertex*>         find_euler_circuit();
	void                  print_euler_circuit(); 
	bool				  is_all_black();
	void				  set_all_white();
	void				  visit(vertex* ver);
};

#endif // !GRAPH