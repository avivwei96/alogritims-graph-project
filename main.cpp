#include<iostream>
#include"un_directed_gragh.h"
#include"directed_graph.h"

int main()
{
	char type;
	int num_of_ver, num_of_arcs;
	cout << "Is the graph directed: y/n ";
	cin >> type >> num_of_ver >> num_of_arcs;
	graph* new_graph;
	if (num_of_arcs < 1 || num_of_arcs < 1)
		cout << "invalid input";
	else if (type == 'n' || type == 'y')
	{
		if (type == 'n')
		{
			new_graph = new un_directedGraph(num_of_ver, num_of_arcs);
		}
		else
		{
			new_graph = new directedGraph(num_of_ver, num_of_arcs);
		}
		new_graph->init();
		new_graph->print_euler_circuit();
	}
	else
		cout << "invalid input";

	return 0;
}