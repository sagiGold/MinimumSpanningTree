#ifndef EDGE_H
#define EDGE_H

#include "Graph.h"

class Edge {
public:
	int u;
	int v;
	int w;

	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
	Edge() : u(0), v(0), w(0) {}

	bool operator <=(const Edge& other) const {
		return w <= other.w;
	}
	bool operator >(const Edge& other) const {
		return w > other.w;
	}
};

vector<Edge> create_edge_vec(Graph& g) 
{
	vector<Edge> res(g.get_m());
	int edge_ind = 0;

	for (int i = 1; i <= g.get_n(); i++) 
	{
		LinkedList<item>* adj_list = g.get_adj_list(i);
		Node<item>* curr = adj_list->head->next;
		while (curr != nullptr) {
			res[edge_ind] = Edge(i, curr->data.vertex, curr->data.weight);
			edge_ind++;
			curr = curr->next;
		}
	}

	return res;
}

#endif