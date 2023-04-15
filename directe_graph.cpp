#include "directed_graph.h"

directedGraph::directedGraph(int amount_of_ver, int amount_of_arcs) : graph(amount_of_ver, amount_of_arcs)
{

}
void directedGraph::add_arc(int num_ver_out, int num_of_ver_in)
{
	my_ver[num_ver_out - 1].add_neighbor(num_of_ver_in);
}
list<int> directedGraph::find_circuit(int num_of_ver)
{

}