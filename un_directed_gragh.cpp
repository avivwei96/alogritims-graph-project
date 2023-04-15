#include "un_directed_gragh.h"



graph* un_directedGraph::init_undeircted_graph(int n, int m)
{
	int vertex1, vertex2;
	un_directedGraph graph = un_directedGraph(n, m);
	for (int i = 0; i < 10; i++)
	{
		cin >> vertex1 >> vertex2;
		add_arc(vertex1, vertex2);
		degree[vertex1 - 1]++;
		degree[vertex2 - 1]++;

	}
}

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
	neighbor1->same_arc = &(*neighbor2);
	neighbor2->same_arc = &(*neighbor1);
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

list<vertex*> un_directedGraph::find_circuit(int num_of_ver)
{
	list<vertex*> ver_list;
	vector<vertex>::iterator it = next(my_ver.begin(), num_of_ver - 1);
	ver_list.push_back(&(*it));
	vector<vertex>::iterator ptr;
	while (ptr != next_avilable(ptr->get_num()))
	{
		mark(ptr->get_num(), next_avilable(ptr->get_num())->get_num());
		ptr = next_avilable(num_of_ver);
		ver_list.push_back(&(*ptr));
	}
	return ver_list;
}

list<vertex*> un_directedGraph::find_euler_circuit()
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

bool un_directedGraph::is_eulerian()
{
	if (!is_even() || !is_connected())
		return false;
	return true;
}

void un_directedGraph::dfs(int node, vector<bool>& visited)
{
	visited[node] = true;
	list<arc>::iterator neighbor;
	for (int i = 0; i < my_ver[node].get_neighbors_num(); i++)
	{
		neighbor = (my_ver[node]).get_neighbor(i);
		if (!visited[neighbor->des])
		{
			dfs(neighbor->des, visited);
		}
	}
}


bool un_directedGraph::is_connected()
{
	int n = my_ver.size();
	vector<bool> visited(n, false);
	dfs(0, visited);
	for (bool v : visited) {
		if (!v) {
			return false;
		}
	}
	return true;
}


bool un_directedGraph::is_even()
{
	int size = degree.size();
	for (int i = 0; i < size; i++)
	{
		if ((degree[i] % 2) != 0)
			return false;
	}
	return true;
}


