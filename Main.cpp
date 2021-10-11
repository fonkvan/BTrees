#include <iostream>
#include "Node.h"
#include "BTree.h"

int main()
{
	int N = 0;
	int M = 5;
	std::cout << "How many elements do you want in your B-Tree?" << std::endl;
	while (N < 400)
	{
		std::cin.clear();
		std::cout << "Please enter a value greater than or equal to 400" << std::endl;
		std::cin >> N;
	}
	BTree BT = BTree(M);
	int* arr = BT.GenerateSequence(N);
	for (int i = 0; i < M - 1; ++i)
	{
		BT.Root->InsertInOrder(arr[i]);
	}
	//BT.BuildBTree(arr);
	for (int i = M - 1; i < N; ++i)
	{
		BT.RecursiveBuild(arr[i], BT.Root);
	}
	BT.GetElementsInRangeN2N(BT.Root);
}