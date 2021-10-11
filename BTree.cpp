#include "BTree.h"
#include "Node.h"
#include <ctime>
#include <iostream>
#include <random>

BTree::BTree(int M)
{
	Root = new Node();
	Root->InitNode(M);
	N = 0;
}

int* BTree::GenerateSequence(int N)
{
	this->N = N;
	int* arr = new int[N];
	std::srand((unsigned int)std::time(NULL));
	int i = 0;
	while (N > 0)
	{
		arr[i] = std::rand()%(3*N);
		--N;
		++i;
	}
	return arr;
}

void BTree::BuildBTree(int sequence[])
{
	int M = Root->M;
	for (int i = 0; i < M - 1; ++i)
	{
		Root->Keys[i] = sequence[i];
	}
	for (int i = M - 1; i < N; ++i)
	{
		Node* NodeToInsert = Root;
		if (Root->CurrentKeys == M)
		{
			Node NewRoot = Node();
			int k = NodeToInsert->SplitNode(Root);
			NewRoot.Leaf = false;
			NewRoot.CurrentKeys = 1;
			NewRoot.Keys[0] = k;
			NewRoot.Nodes[0] = Root->Nodes[0];
			NewRoot.Nodes[1] = Root->Nodes[1];
			Root = &NewRoot;
		}
		Node* NextNode = new Node();
		NextNode->InitNode(M);
		while (!NodeToInsert->Leaf)
		{
			//find appropriate leaf
			for (int j = 0; j < M; ++j)
			{
				int Check = NodeToInsert->Keys[j];
				Node* Child = NodeToInsert->Nodes[j];
				if (sequence[i] <= Check)
				{
					NextNode = NodeToInsert->Nodes[j];
					break;
				}
				if (NodeToInsert->Nodes[j]->CurrentKeys == M)
				{
					
				}
			}
			if (NextNode->Leaf && NextNode->CurrentKeys == M)
			{
				int k = NodeToInsert->SplitNode(NextNode);
			}
			//if leaf is full, split leaf
			//otherwise store leaf
			else
			{
				NodeToInsert = NextNode;
			}
		}
		//insert sequence[i] into leaf
		NextNode->InsertInOrder(sequence[i]);
	}
}

void BTree::GetElementsInRangeN2N(Node* n)
{
	int M = Root->M;
	if (n->Leaf)
	{
		return;
	}
	for (int i = 0; i < M; ++i)
	{
		int j = n->Keys[i];
		if (j >= N && j <= (2*N))
		{
			std::cout << n->Keys[i] << std::endl;
			GetElementsInRangeN2N(n->Nodes[i]);
		}
	}
}

void BTree::RecursiveBuild(int i, Node* n)
{
	int M = Root->M;
	if (n == Root && n->CurrentKeys == M)
	{
		int i = Root->SplitNode(Root);
		return;
	}
	if (n->Leaf)
	{
		n->InsertInOrder(i);
	}
	else
	{
		Node next = Node();
		for (int j = 0; j < M; ++j)
		{
			if (i <= n->Keys[j])
			{
				next = *n->Nodes[j];
				break;
			}
		}
		RecursiveBuild(i, &next);
	}
}