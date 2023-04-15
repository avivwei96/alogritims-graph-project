#ifndef VERTEX
#define VERTEX
#include <iostream>
#include<vector>
using namespace std;
enum color{WHITE, GRAY, BLACK};
class vertex
{
	int my_num;
	color my_color;
	vector<int> my_neighbors;
public:
	vertex(int my_num) : my_num(my_num) { my_color = WHITE; }
	void set_color(color n_color) { my_color = n_color; }
	void add_neighbor(int neighbot_n) { my_neighbors.push_back(neighbot_n); }
};
#endif // !VERTEX

