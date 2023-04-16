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

void directedGraph::mark(list<arc>::iterator curr_arc)
{
	// this functio mark an arc
	curr_arc->is_visited = true;
}

bool directedGraph::is_strongly_connected()
{
	// this function checks if the graph is strongly connected
	set_all_white();
	visit(&(*(my_ver.begin())));
	if (!is_all_black())
		return false;
	directedGraph T_graph = creat_transpose();
	T_graph.set_all_white();
	T_graph.visit(&(*(my_ver.begin())));
	if (T_graph.is_all_black())
		return true;
	return false;
}

directedGraph directedGraph::creat_transpose()
{
	// this function create a transpose tree
	directedGraph T_graph(amount_of_ver, amount_of_arcs);
	for (auto& ver : my_ver)
	{
		for (auto& arc : ver.get_list())
			T_graph.my_ver[arc.des - 1].add_neighbor(ver.get_num());
	}
	return T_graph;
}

void directedGraph::init()
{
	// this function intialize the graph from user input
	int vertex1, vertex2;
	for (int i = 0; i < amount_of_arcs; i++)
	{
		cin >> vertex1 >> vertex2;
		add_arc(vertex1, vertex2);
	}

}

bool directedGraph::is_euler_graph()
{
	if (!is_strongly_connected())
		return false;
	for (int i = 0; i < amount_of_ver; i++)
	{
		if (in_degree[i] != out_degree[i])
			return false;
	}
	return true;
}
