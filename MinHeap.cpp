#include "MinHeap.h"

MinHeap:: ~MinHeap()
{
	delete data;
}

MinHeap::MinHeap(int size)
{
	maxSize = size;
	heapSize = 0;
	data = new Pair[size];
}

void MinHeap::FixHeap(int node)
{
	int min;
	int left = this->left(node);
	int right = this->right(node);

	if (left < heapSize && data[left].key < data[node].key) {
		min = left;
	}
	else min = node;
	if (right < heapSize && data[right].key < data[min].key) {
		min = right;
	}

	if (min != node) {

		swap(data[min], data[node]);
		FixHeap(min);
	}
}

const Pair& MinHeap::DeleteMin()
{
	if (heapSize < 1) {
		//throw new exception("Error : Heap is empty");
		exit(1);
	}
	Pair min = data[0];
	--heapSize;

	data[0] = data[heapSize];
	FixHeap(0);

	return min;
}

void MinHeap::BuildMinHeap(vector<int> array, int arraySize)
{
	if (arraySize > maxSize)
	{
		return;
	}

	for (int i = 0; i < arraySize; ++i)
	{
		data[i].key = array[i];
		data[i].data = i;
	}

	heapSize = arraySize;

	for (int i = heapSize / 2 - 1; i >= 0; --i)
	{
		FixHeap(i);
	}
}

void MinHeap::DecreaseKey(int index, int newKey) 
{
	int location;

	for (int i = 0; i < heapSize; i++)
		if (data[i].data == index)
		{
			data[i].key = newKey;
			location = i;
			break;
		}

	while (location > 0 && data[parent(location)].key > data[location].key)
	{
		swap(data[location], data[parent(location)]);
		location = parent(location);
	}
}