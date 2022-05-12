#include "Graph.h"

void Graph::make_empty_graph(int _n){
	n = _n;
	if (n < 0)
		return;

	else if (n == 0)
		adj_list_arr = nullptr;

	else
		adj_list_arr = new LinkedList<item>[n+1];
}

bool Graph::is_adjacent(int u, int v) {
	if (u > 0 && u <= n) {
		Node<item>* current = adj_list_arr[u].head->next;
		while (current != nullptr) {
			if (current->data.vertex == v)
				return true;
			current = current->next;
		}
	}
	return false;
}

LinkedList<item>* Graph::get_adj_list(int u) {
	LinkedList<item>* res = nullptr;
	if (u > 0 && u <= n)
		res = &adj_list_arr[u];

	return res;
}

void Graph::add_edge(int u, int v, int c) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;
	item new_item = item(v, c);
	adj_list_arr[u].insert_to_end(new_item);
}

void Graph::remove_edge(int u, int v) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;
	Node<item>* temp = adj_list_arr[u].head;
	while (temp->next->data.vertex != v || temp->next == nullptr)
		temp = temp->next;
	
	if (temp->next->data.vertex == v)
		adj_list_arr[u].delete_after(temp);
	m -= 1;
}