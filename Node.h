#pragma once
class Node
{
public:
	int* Keys;
	int M;
	Node** Nodes;
	int CurrentKeys;
	bool Leaf;
	Node();
	void InitNode(int M);
	int SplitNode(Node* NodeToSplit);
	void InsertInOrder(int i);
};

