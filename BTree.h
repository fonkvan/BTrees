#pragma once

class Node;
class BTree
{
public:
	Node* Root;
	int N;

	BTree(int M);
	int* GenerateSequence(int N);
	void Insert(int i);
	void GetElementsInRangeN2N(Node* n);
};

