#include "directed_graph.h"

directedGraph::directedGraph(int amount_of_ver, int amount_of_arcs) : graph(amount_of_ver, amount_of_arcs)
{
	// this funtion intialize the directed graph part of the graph
	in_degree.reserve(amount_of_arcs);
	for (int i = 1; i <= amount_of_ver; i++)
		in_degree.push_back(0);
	out_degree.reserve(amount_of_arcs);
	for (int i = 1; i <= amount_of_ver; i++)
		out_degree.push_back(0);
}
void directedGraph::add_arc(int num_ver_out, int num_ver_in)
{
	// this function add arc to the graph
	my_ver[num_ver_out - 1].add_neighbor(num_ver_in);
	in_degree[num_ver_in - 1]++;
	out_degree[num_ver_out - 1]++;
}
list<vertex*> directedGraph::find_circuit(int num_of_ver)
{
	// this function works only on euler graph
	// this function find a circuit that starts at num of ver
	list<vertex*> ver_list;
	vector<vertex>::iterator it = next(my_ver.begin(), num_of_ver - 1);
	ver_list.push_back(&(*it));
	list<arc>::iterator ptr;
	bool is_all_edges_used = false;
	while (!is_all_edges_used)
	{
		ptr = it->get_list_it();
		ptr->is_visited = true;
		ptr++;
		it = next(my_ver.begin(), ptr->des - 1);
		if (it->is_last(ptr))
			is_all_edges_used = true;
		ver_list.push_back(&(*it));
	}
	return ver_list;
}

list<vertex*> directedGraph::find_euler()
{
	list<vertex*> ver_list;
	vector<vertex>::iterator vec_it = my_ver.begin();
	ver_list.push_back(&(*vec_it));
	list<vertex*>::iterator list_it = ver_list.begin();

	while (list_it != ver_list.end())
	{
		list<vertex*> temp_list = find_circuit(vec_it->get_num());
		if ((!temp_list.empty()))
			ver_list.insert(list_it, ++(temp_list.begin()), temp_list.end());
		list_it++;
	}
	return ver_list;
}

bool directedGraph::is_strongly_connected()
{
	return true;
}

bool directedGraph::is_euler_graph()
{
	for (int i = 0; i < amount_of_ver; i++)
	{
		if (in_degree[i] != out_degree[i])
			return false;
	}
}
void directedGraph::visit(vertex* ver)
{
	ver->set_color(GRAY);
	for (auto& curr_ver : ver->get_list())
	{
		if (my_ver[curr_ver.des - 1].get_color() == WHITE)
		{
			visit(&(my_ver[curr_ver.des - 1]));
		}
	}
	ver->set_color(BLACK);

}