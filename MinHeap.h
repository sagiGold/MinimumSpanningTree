#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Pair
{
	int data;
	int key;
};

class MinHeap
{
	Pair* data;
	int heapSize;
	int maxSize;

	int parent(int node) const { return (node - 1) / 2; }
	int left(int node) const { return 2 * node + 1; }
	int right(int node) const { return 2 * node + 2; }
	void FixHeap(int node);

public:

	~MinHeap();
	MinHeap(int size);
	MinHeap(const MinHeap& h) = delete;

	int GetHeapSize() { return heapSize; }
	const Pair& DeleteMin();

	void DecreaseKey(int location, int newKey);
	void BuildMinHeap(vector<int> array, int size); // implemented by Floyd algorithm
};

