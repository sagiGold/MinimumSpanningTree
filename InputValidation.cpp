//#include "InputValidation.h"
//
//bool IsInvalidEdge(Edge edge, int n)
//{
//	return edge.u < 1 || edge.u > n || edge.v < 1 || edge.v > n;
//}
//
//bool IsConnectedGraph(Graph& g) 
//{
//	bool res = true;
//	vector<string> colors(g.get_n() + 1);
//	for (int i = 1; i <= g.get_n(); i++) {
//		colors[i] = "W";
//	}
//	visit(g, colors, 1);
//
//	for (int i = 1; i <= g.get_n(); i++) {
//		if (colors[i] != "B") {
//			res = false;
//			break;
//		}
//	}
//	return res;
//}
//
//void CheckConnectivity(Graph& g, ofstream& outputFile)
//{
//	if (!IsConnectedGraph(g))
//	{
//		cout << "No MST" << endl;
//		outputFile << "No MST" << endl;
//		exit(1);
//	}
//}
//void invalid_input(std::ofstream& outputFile) {
//	outputFile << "Invalid Input" << endl;
//	cout << "Invalid Input" << endl;
//	outputFile.close();
//	exit(1);
//}
//
//void visit(Graph& g, vector<string>& colors, int vertex) 
//{
//	colors[vertex] = "G";
//	LinkedList<item>* adj_list = g.get_adj_list(vertex);
//	Node<item>* curr = adj_list->head->next;
//
//	while (curr != nullptr) {
//		if (colors[curr->data.vertex] == "W") {
//			visit(g, colors, curr->data.vertex);
//		}
//		curr = curr->next;
//	}
//	colors[vertex] = "B";
//}
//
//// input n costs 1 int
//// input m costs 1 int
//// input edge costs 3 * m int
//// input edge to remove costs 2 int
//// validFileLength = 1 + 1 + 3 * m + 2;
//
//Graph& BuildGraph(string file_name, Edge* edge_to_delete, std::ofstream& outputFile)
//{
//	int n, m, dummy;
//	Edge edge;
//	Graph G;
//	fstream inputFile(file_name);
//
//	if (!inputFile.is_open()) {
//		cout << "File does not exist" << endl;
//		exit(1);
//	}
//	inputFile >> n;
//	inputFile >> m;
//
//	if (inputFile.fail() || n <= 0 || m < 0)
//		invalid_input(outputFile);
//
//	int validFileLength = 3 * m + 2;
//	int countValidEdges = 0;
//	G.make_empty_graph(n);
//	G.set_m(2 * m);
//	for (int i = 0; i < m; i++)
//	{
//		inputFile >> edge.u;
//		inputFile >> edge.v;
//		inputFile >> edge.w;
//
//		if (inputFile.fail() || IsInvalidEdge(edge, n))
//			invalid_input(outputFile);
//
//		G.add_edge(edge.u, edge.v, edge.w);
//		G.add_edge(edge.v, edge.u, edge.w);
//		countValidEdges += 3;
//	}
//	inputFile >> edge_to_delete->u;
//	inputFile >> edge_to_delete->v;
//	countValidEdges += 2;
//
//	if (inputFile.fail() || countValidEdges != validFileLength)
//		invalid_input(outputFile);
//
//	inputFile >> dummy;
//	if (!inputFile.eof())
//		invalid_input(outputFile);
//
//	return G;
//}
//
//
//
//
//