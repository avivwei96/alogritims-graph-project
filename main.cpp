#include<iostream>
#include"un_directed_gragh.h"
#include"directed_graph.h"

int main()
{
	char type;
	int num_of_ver, num_of_arcs;
	cout << "Is the graph directed: y/n ";
	cin >> type >> num_of_ver >> num_of_arcs;

	if (type == 'n')
	{
		un_directedGraph new_graph(num_of_ver, num_of_arcs);
		list<vertex*> euler_circuit;
		new_graph.init_undeircted_graph();
		if (new_graph.is_eulerian())
		{
			euler_circuit = new_graph.find_euler_circuit();
			cout << "The graph is aulerian:\n(";
			for (auto& ver : euler_circuit)
				cout << ver->get_num() << ",";
			cout << ")\n";
		}
		else
			cout << "The graph is n0t aulerian:\n";
	}
	return 0;
}