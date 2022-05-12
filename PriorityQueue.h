#pragma once
#include "MinHeap.h"

class PriorityQueue
{
	int m_Size;
	MinHeap m_Heap;

public:

	PriorityQueue(int i_Size) : m_Heap(i_Size), m_Size(i_Size) {};

	void Build(vector<int> i_Min, int i_Size);
	void DecreaseKey(int i_Place, int i_NewKey);

	bool IsEmpty();
	int DeleteMin();
};
