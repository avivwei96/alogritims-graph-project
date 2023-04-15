#ifndef VERTEX
#define VERTEX
#include <iostream>
#include<list>
using namespace std;
enum color{WHITE, GRAY, BLACK};

struct arc {
	int des;
	bool is_visited;
	arc* same_arc;
}typedef arc;

class vertex
{
	int my_num;
	color my_color;
	list<arc> my_neighbors;
	list<arc>::iterator ptr;
public:
	vertex(int my_num) : my_num(my_num) { my_color = WHITE;}
	int get_num() { return my_num; }
	void set_color(color n_color) { my_color = n_color; }
	color get_color() { return my_color; }
	list<arc>& get_list() { return my_neighbors; }
	void add_neighbor(int neighbot_n) { 
		arc my_arc;
		my_arc.des = neighbot_n;
		my_arc.is_visited = false;
		my_neighbors.push_back(my_arc);
		ptr = my_neighbors.begin();
	}
	list<arc>::iterator get_list_it() { return ptr; }
	bool is_last(list<arc>::iterator it)const { return it == my_neighbors.end(); }
};
#endif // !VERTEX

