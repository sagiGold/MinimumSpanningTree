#include <iostream>
#include <vector>
#include "Graph.h"
#include "InputValidation.h"
#include "QuickSort.h"
#include "Kruskal.h"
#include "Prim.h"

/*Assumption from forum discusion :
1) Kruskal gets sort-edges vector instead of doing so inside the algorithem.
2) The two algorithem return the weight of the MST, not the graph itself.
3) using exit(1) method for invalid input as requested.	*/

void RunProgram(int argc, char** argv);
void RunPrim(Graph& g, ofstream& outputFile);
void RunKruskal(vector<Edge> edge_vec, Graph& g, ofstream& outputFile);
void RunKruskalAfterRemoveEdge(vector<Edge> edge_vec, Edge& edge_to_delete, Graph& g, ofstream& outputFile);
void RemoveEdgeFromVec(vector<Edge>& edge_vec, Edge& edge_to_delete);

int main(int argc, char ** argv) 
{
	RunProgram(argc, argv);
}

void RunProgram(int argc, char** argv)
{
	ofstream outputFile(argv[2]);
	Edge edge_to_delete;
	vector<Edge> edge_vec;
	Graph g;
	BuildGraph(argv[1], &edge_to_delete, outputFile, g);

	CheckConnectivity(g, outputFile);
	edge_vec = create_edge_vec(g);
	quickSort<Edge>(edge_vec, 0, g.get_m() - 1);

	RunKruskal(edge_vec, g, outputFile);
	RunPrim(g, outputFile);
	RunKruskalAfterRemoveEdge(edge_vec, edge_to_delete, g, outputFile);
	outputFile.close();
}

void RunPrim(Graph& g, ofstream& outputFile)
{
	int prim = Prim(g);
	cout << "Prim " << prim << endl;
	outputFile << "Prim " << prim << endl;
}

void RunKruskal(vector<Edge> edge_vec, Graph& g, ofstream& outputFile)
{
	int kruskal = Kruskal(edge_vec, g.get_n(), g.get_m());
	cout << "Kruskal " << kruskal << endl;
	outputFile << "Kruskal " << kruskal << endl;
}

void RunKruskalAfterRemoveEdge(vector<Edge> edge_vec, Edge& edge_to_delete, Graph& g, ofstream& outputFile)
{
	if (IsInvalidEdge(edge_to_delete, g.get_n()))
		invalid_input(outputFile);

	g.remove_edge(edge_to_delete.v, edge_to_delete.u);
	g.remove_edge(edge_to_delete.u, edge_to_delete.v);
	CheckConnectivity(g, outputFile);
	RemoveEdgeFromVec(edge_vec, edge_to_delete);

	int kruskal2 = Kruskal(edge_vec, g.get_n(), g.get_m());

	cout << "Kruskal2 " << kruskal2 << endl;
	outputFile << "Kruskal2 " << kruskal2 << endl;
}

void RemoveEdgeFromVec(vector<Edge>& edge_vec, Edge& edge_to_delete)
{
	for (int i = 0; i < edge_vec.size(); i++) {
		if (edge_vec[i].u == edge_to_delete.u && edge_vec[i].v == edge_to_delete.v) {
			edge_vec.erase(edge_vec.begin() + i);
		}
	}

	for (int i = 0; i < edge_vec.size(); i++) {
		if (edge_vec[i].u == edge_to_delete.v && edge_vec[i].v == edge_to_delete.u) {
			edge_vec.erase(edge_vec.begin() + i);
		}
	}
}
