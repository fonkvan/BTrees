#pragma once

class Node;
class BTree
{
public:
	Node* Root;
	int N;

	BTree(int M);
	int* GenerateSequence(int N);
	void BuildBTree(int sequence[]);
	void RecursiveBuild(int i, Node* n);
	void GetElementsInRangeN2N(Node* n);
};

