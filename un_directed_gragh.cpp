#include "un_directed_gragh.h"


un_directedGraph::un_directedGraph(int amount_of_ver, int amount_of_arcs) : graph(amount_of_ver, amount_of_arcs)
{
	// this is a c'tor of undirected graph
	degree.reserve(amount_of_arcs);
	for (int i = 1; i <= amount_of_ver; i++)
		degree.push_back(0);
	
}

void un_directedGraph::init()
{
	// this function intialize undirected graph from user input
	int vertex1, vertex2;
	try {
		for (int i = 0; i < amount_of_arcs; i++) {
			cin >> vertex1 >> vertex2;
			if (vertex1 > amount_of_ver || vertex2 > amount_of_ver) {
				throw GraphInitException();
			}
			add_arc(vertex1, vertex2);
		}
	}
	catch (GraphInitException& e) {
		cout << e.what() << endl;
		exit(0);
	}
}

void un_directedGraph::same_arc(int num_ver1, int num_ver2)
{
	// this intialize the pointer to the same arc of other vec
	list<arc>::iterator neighbor1 = --(my_ver[num_ver1 - 1].get_list().end());
	list<arc>::iterator neighbor2 = --(my_ver[num_ver2 - 1].get_list().end());
	neighbor1->same_arc = &(*neighbor2);
	neighbor2->same_arc = &(*neighbor1);
}

void un_directedGraph::mark(list<arc>::iterator curr_arc)
{
	// this functin mark arc that is been visited
	curr_arc->is_visited = true;
	curr_arc->same_arc->is_visited = true;
}

void un_directedGraph::add_arc(int num_ver1, int num_ver2)
{
	// this funtion add arc to the graph
	my_ver[num_ver1 - 1].add_neighbor(num_ver2);
	degree[num_ver1 - 1]++;
	my_ver[num_ver2 - 1].add_neighbor(num_ver1);
	degree[num_ver2 - 1]++;
	same_arc(num_ver1, num_ver2);
}

bool un_directedGraph::is_euler_graph()
{
	// this function checks if the graph is aulerain
	if (!is_even() || !is_connected())
		return false;
	return true;
}

bool un_directedGraph::is_connected()
{
	// this functio checks if the graph is connected
	visit(&(*(my_ver.begin())));
	for (auto& ver : my_ver)
	{
		if (ver.get_color() != BLACK)
			return false;
	}
	return true;
}

bool un_directedGraph::is_even()
{
	// this function checks if the dgrees are even
	int size = degree.size();
	for (int i = 0; i < size; i++)
	{
		if ((degree[i] % 2) != 0)
			return false;
	}
	return true;
}
