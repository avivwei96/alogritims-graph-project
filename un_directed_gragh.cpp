#include "un_directed_gragh.h"



void un_directedGraph::init_undeircted_graph()
{
	int vertex1, vertex2;
	for(int i = 0; i < amount_of_arcs; i++)
	{
		cin >> vertex1 >> vertex2;
		add_arc(vertex1, vertex2);
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
	list<arc>::iterator neighbor1 = --(my_ver[num_ver1 - 1].get_list().end());
	list<arc>::iterator neighbor2 = --(my_ver[num_ver2 - 1].get_list().end());
	neighbor1->same_arc = &(*neighbor2);
	neighbor2->same_arc = &(*neighbor1);
}

void un_directedGraph::mark(list<arc>::iterator curr_arc)
{
	curr_arc->is_visited = true;
	curr_arc->same_arc->is_visited = true;
}

list<arc>::iterator un_directedGraph::next_avilable(int num_ver)
{
	vector<vertex>::iterator it = next(my_ver.begin(), num_ver - 1);
	list<arc>::iterator ptr = it->get_ptr();
	while(ptr != it->get_list().end())
	{
		if (!(ptr->is_visited))
		{
			return ptr;
		}
		ptr++;
	}
	return ptr;
}

void un_directedGraph::add_arc(int num_ver1, int num_ver2)
{
	my_ver[num_ver1 - 1].add_neighbor(num_ver2);
	degree[num_ver1 - 1]++;
	my_ver[num_ver2 - 1].add_neighbor(num_ver1);
	degree[num_ver2 - 1]++;
	same_arc(num_ver1, num_ver2);
}

list<vertex*> un_directedGraph::find_circuit(int num_of_ver)
{
	list<vertex*> ver_list;
	vector<vertex>::iterator it = next(my_ver.begin(), num_of_ver - 1);
	ver_list.push_back(&(*it));
	list<arc>::iterator ptr = it->get_ptr();
	while (ptr != it->get_list().end())
	{
		mark(ptr);
		it = next(my_ver.begin(), ptr->des - 1);
		ver_list.push_back(&(*it));
		ptr = it->get_ptr();
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
		list<vertex*> temp_list = find_circuit((*list_it)->get_num());
		if ((!temp_list.empty()))
		{
			list<vertex*>::iterator temp = ++list_it;
			list_it--;
			temp_list.pop_front();
			ver_list.insert(temp, temp_list.begin(), temp_list.end());
			list_it++;
		}
	}
	return ver_list;
}

bool un_directedGraph::is_eulerian()
{
	if (!is_even() || !is_connected())
		return false;
	return true;
}

void un_directedGraph::visit(vector<vertex>::iterator curr_ver)
{
	curr_ver->set_color(GRAY);
	for (auto& curr_ver : curr_ver->get_list())
	{
		if (my_ver[curr_ver.des - 1].get_color() == WHITE)
		{
			visit(my_ver.begin() + (curr_ver.des - 1));
		}
	}
	curr_ver->set_color(BLACK);

}

bool un_directedGraph::is_connected()
{
	visit(my_ver.begin());
	for (auto& ver : my_ver)
	{
		if (ver.get_color() != BLACK)
			return false;
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


