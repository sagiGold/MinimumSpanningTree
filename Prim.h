#pragma once
#include <vector>
#include "Graph.h"
#include "PriorityQueue.h"


 int Prim(Graph& G)
{
	 int vertexU, MST_Weight = 0;
	 int numOfVertexes = G.get_n() + 1; // vertex 0 is a dummy
	 bool* vertexOutOfQueue = new bool[numOfVertexes]{ false };
	 vector<int> minWeightToVertex(numOfVertexes);
	 PriorityQueue Q(numOfVertexes);
	 LinkedList<item>* adjList;
	 Node<item>* neighborOfU;

	 minWeightToVertex[0] = INT_MAX; // just a dummy -> ignore 
	 minWeightToVertex[1] = 0;
	 for (int i = 2; i < numOfVertexes; i++)
		 minWeightToVertex[i] = INT_MAX;

	 Q.Build(minWeightToVertex, numOfVertexes); 
	 while (!Q.IsEmpty())
	 {
		 vertexU = Q.DeleteMin();
		 vertexOutOfQueue[vertexU] = true;
		 adjList = G.get_adj_list(vertexU);
		 neighborOfU = adjList->head->next;
		 while (neighborOfU != nullptr) 
		 {
			 if ((!vertexOutOfQueue[neighborOfU->data.vertex]) && 
				 (neighborOfU->data.weight < minWeightToVertex[neighborOfU->data.vertex]))
			 {
				 if (minWeightToVertex[neighborOfU->data.vertex] != INT_MAX)
					 MST_Weight += neighborOfU->data.weight - minWeightToVertex[neighborOfU->data.vertex];
				 else
					 MST_Weight += neighborOfU->data.weight;

				 minWeightToVertex[neighborOfU->data.vertex] = neighborOfU->data.weight;
				 Q.DecreaseKey(neighborOfU->data.vertex, neighborOfU->data.weight);
			 }

			 neighborOfU = neighborOfU->next;
		 }
	 }
	 delete[] vertexOutOfQueue;

	 return MST_Weight;
}