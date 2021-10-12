#include "Node.h"

Node::Node()
{
	M = 0;
	Keys = new int[0];
	Nodes = new Node*[1];
	Leaf = true;
	CurrentKeys = 0;
	CurrentChildren = 0;
}

void Node::InitNode(int M)
{
	this->M = M;
	Keys = new int[M];
	for (int i = 0; i < M; ++i)
	{
		Keys[i] = -1;
	}
	Nodes = new Node * [M + 1];
	Leaf = true;
	CurrentKeys = 0;
	CurrentChildren = 0;
}

int Node::SplitNode(int index, Node* NodeToSplit)
{
	Node left = Node();
	Node right = Node();
	left.InitNode(M);
	right.InitNode(M);
	left.Leaf = NodeToSplit->Leaf;
	right.Leaf = NodeToSplit->Leaf;
	Leaf = false;
	NodeToSplit->Leaf = false;
	int HalfSize = M/2;
	int median = NodeToSplit->Keys[HalfSize];
	for (int i = 0; i < HalfSize; ++i)
	{
		left.Keys[i] = NodeToSplit->Keys[i];
		right.Keys[i] = NodeToSplit->Keys[i + HalfSize + 1];
	}
	//if (!left.Leaf)
	//{
	//	for (int i = 0; i < HalfSize + 1; ++i)
	//	{
	//		left.Nodes[i] = NodeToSplit->Nodes[i];
	//		right.Nodes[i] = NodeToSplit->Nodes[i + HalfSize + 1];
	//		NodeToSplit->Nodes[i] = nullptr;
	//		NodeToSplit->Nodes[i + HalfSize + 1] = nullptr;
	//		NodeToSplit->Keys[i] = -1;
	//		NodeToSplit->Keys[i + HalfSize] = -1;
	//	}
	//}
	for (int i = 0; i < HalfSize + 1; ++i)
	{
		left.Nodes[i] = NodeToSplit->Nodes[i];
		right.Nodes[i] = NodeToSplit->Nodes[i + HalfSize + 1];
		//NodeToSplit->Nodes[i] = nullptr;
		//NodeToSplit->Nodes[i + HalfSize + 1] = nullptr;
		NodeToSplit->Keys[i] = -1;
		NodeToSplit->Keys[i + HalfSize] = -1;
	}
	Nodes[index] = &left;
	Nodes[index + 1] = &right;
	left.CurrentChildren = NodeToSplit->CurrentChildren/2;
	right.CurrentChildren = NodeToSplit->CurrentChildren / 2;
	CurrentKeys += 1;
	CurrentChildren += 2;
	InsertInOrder(median);
	return median;
}

void Node::InsertInOrder(int i)
{
	int k = 0;
	int temp;
	for (k; k < M; ++k)
	{
		if (Keys[k] < 0)
		{
			Keys[k] = i;
			break;
		}
		if (Keys[k] >= i)
		{
			temp = Keys[k];
			Keys[k] = i;
			i = temp;
		}
	}
	++CurrentKeys;
	/*int k = M - 1;
	while (Keys[k] > i && k > 0)
	{
		Keys[k+1] = Keys[k];
		--k;
	}
	Keys[k] = i;
	++CurrentKeys;*/
}