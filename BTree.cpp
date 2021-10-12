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

void BTree::Insert(int i)
{
	int M = Root->M;
	if (Root->CurrentKeys == M)
	{
		Node s = Node();
		s.InitNode(M);
		s.Nodes[0] = Root;
		s.SplitNode(0, Root);
		Root = &s;
	}
	Node* Next = Root;
	if (Next->Leaf)
	{
		Next->InsertInOrder(i);
	}
	else
	{
		for (int j = 0; j < M; ++j)
		{
			if (i <= Next->Keys[j] || Next->Keys[j] < 0)
			{
				if (Next->Nodes[j]->CurrentKeys == M)
				{
					Next->SplitNode(j, Next->Nodes[j]);
				}
				Next = Next->Nodes[j];
				break;
			}
		}
		Next->InsertInOrder(i);
	}
}

void BTree::GetElementsInRangeN2N(Node* n)
{
	int M = Root->M;
	int C = n->CurrentChildren;
	if (n == nullptr)
	{
		return;
	}
	for (int i = 0; i < C - 1; ++i)
	{
		int j = n->Keys[i]; //access violation
		if (j >= N && j <= (2*N))
		{
			std::cout << n->Keys[i] << std::endl;
			GetElementsInRangeN2N(n->Nodes[i]);
		}
		else
		{
			GetElementsInRangeN2N(n->Nodes[i]);
		}
	}
}
