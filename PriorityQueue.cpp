#include "PriorityQueue.h"

void PriorityQueue::Build(vector<int> min, int i_Size)
{
	m_Heap.BuildMinHeap(min, i_Size);
}

void PriorityQueue::DecreaseKey(int place, int newKey)
{
	m_Heap.DecreaseKey(place, newKey);
}

bool PriorityQueue::IsEmpty()
{
	return m_Heap.GetHeapSize() == 1; // because vertex 0 is a dummy
}

int PriorityQueue::DeleteMin()
{
	--m_Size;
	return m_Heap.DeleteMin().data;
}