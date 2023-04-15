#include "directed_graph.h"

directedGraph::directedGraph(int amount_of_ver, int amount_of_arcs) : graph(amount_of_ver, amount_of_arcs)
{
	in_degree.reserve(amount_of_arcs);
	for (int i = 1; i <= amount_of_ver; i++)
		in_degree.push_back(0);
	out_degree.reserve(amount_of_arcs);
	for (int i = 1; i <= amount_of_ver; i++)
		out_degree.push_back(0);
}
void directedGraph::add_arc(int num_ver_out, int num_ver_in)
{
	my_ver[num_ver_out - 1].add_neighbor(num_ver_in);
	in_degree[num_ver_in - 1]++;
	out_degree[num_ver_out - 1]++;
}
list<int> directedGraph::find_circuit(int num_of_ver)
{
	// this function works only on euler graph
	// this function find a circuit that starts at num of ver
	list<vertex&> ver_list;
	vector<vertex>::iterator it = next(my_ver.begin(), num_of_ver - 1);
	ver_list.push_back(*it);
	list<arc>::iterator ptr;
	bool
	while (true)
	{
		ptr = it->get_list_it();
		ptr->is_visited = true;
		ptr++;
		it = next(my_ver.begin(), ptr->des - 1);
		if (it->is_last(ptr))
			break;
	}

}