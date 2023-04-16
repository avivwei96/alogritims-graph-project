#include "graph.h"

graph::graph(int amount_of_ver, int amount_of_arcs) : amount_of_ver(amount_of_ver), amount_of_arcs(amount_of_arcs)
{
	// this is a c'tor function 
	// the function create new graph and initialize it
	for (int i = 1; i <= amount_of_ver; i++)
	{
		vertex new_ver(i);
		my_ver.push_back(new_ver);
	}
}

list<vertex*> graph::find_euler_circuit()
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

void graph::print_euler_circuit()
{
	// this function print euler circuit other wise it prints that The graph is not aulerian
	if(is_euler_graph())
	{
		list<vertex*> euler_circuit;
		euler_circuit = find_euler_circuit();
		cout << "The graph is aulerian:\n(";
		for (auto& ver : euler_circuit)
			cout << ver->get_num() << ",";
		cout << ")\n";
	}
	else
		cout << "The graph is not aulerian\n";
}

list<vertex*> graph::find_circuit(int num_of_ver)
{
	// this function works only on euler graph
	// this function find a circuit that starts at num of ver
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

bool graph::is_all_black()
{
	// this function checks if the ver are colored black
	for (auto& ver : my_ver)
	{
		if (ver.get_color() != BLACK)
			return false;
	}
	return true;
}

void graph::set_all_white()
{
	// this function set all the ver to white
	for (auto& ver : my_ver)
	{
		ver.set_color(WHITE);
	}
}

void graph::visit(vertex* ver)
{
	// this is a visit function of the dfs algoritm
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