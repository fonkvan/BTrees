#pragma once

class Node
{
private:
	int* Keys;
	int M;
	Node** Nodes;
	int CurrentKeys;
	int CurrentChildren;
	bool Leaf;
public:
	Node();
	void InitNode(int M);
	int SplitNode(int index, Node* NodeToSplit);
	void InsertInOrder(int i);
	friend class BTree;
};

