#include "un_directed_gragh.h"

un_directedGraph::un_directedGraph(int amount_of_ver, int amount_of_arcs) : graph(amount_of_ver, amount_of_arcs)
{
	degree.reserve(amount_of_arcs);
	for (int i = 1; i <= amount_of_ver; i++)
		degree.push_back(0);
	
}
void un_directedGraph::same_arc(int num_ver1, int num_ver2)
{
	list<arc>::iterator neighbor1 = my_ver[num_ver1].get_neighbor(num_ver2);
	list<arc>::iterator neighbor2 = my_ver[num_ver2].get_neighbor(num_ver1);
	neighbor1->same_arc = neighbor2;
	neighbor2->same_arc = neighbor1;
}
void un_directedGraph::mark(int num_ver1, int num_ver2)
{
	list<arc>::iterator neighbor1 = my_ver[num_ver1].get_neighbor(num_ver2);
	list<arc>::iterator neighbor2 = my_ver[num_ver2].get_neighbor(num_ver1);
	neighbor1->is_visited = true;
	neighbor2->is_visited = true;

}
vector<vertex>::iterator un_directedGraph::next_avilable(int num_ver)
{
	vector<vertex>::iterator it = next(my_ver.begin(), num_ver - 1);
	list<arc>::iterator ptr;
	for (int i = 0; i < it->get_neighbors_num(); i++)
	{
		ptr = it->get_neighbor(i);
		if (!(ptr->is_visited))
		{
			return next(my_ver.begin(), ptr->des - 1);
		}
	}
	return it;
}
void un_directedGraph::add_arc(int num_ver1, int num_ver2)
{
	my_ver[num_ver1].add_neighbor(num_ver2);
	degree[num_ver1 - 1]++;
	my_ver[num_ver2].add_neighbor(num_ver1);
	degree[num_ver2 - 1]++;
	same_arc(num_ver1, num_ver2);
}

list<int> un_directedGraph::find_circuit(int num_of_ver)
{
	list<vertex&> ver_list;
	vector<vertex>::iterator it = next(my_ver.begin(), num_of_ver - 1);
	ver_list.push_back(*it);
	vector<vertex>::iterator ptr;
	while (ptr != next_avilable(ptr->get_my_num()))
	{
		mark(ptr->get_my_num(), next_avilable(ptr->get_my_num())->get_my_num());
		ptr = next_avilable(num_of_ver);
		ver_list.push_back(*ptr);
	}
}

list<int> un_directedGraph::find_euler_circuit()
{
	list<int> L = find_circuit(my_ver[0].get_my_num());
}

