#include "BinaryTree.h"
#include<stdio.h>
#include<string.h>

void TestCreateBinaryTree()
{
	char array[] = "ABD###CE##F";
	PNode pRoot = NULL;
	int len = 0;
	len = strlen(array);

	CreateBinaryTree(&pRoot, array, len, '#');
}

void TestCopyBinaryTree()
{
	char array[] = "ABD###CE##F";
	PNode pRoot = NULL;
	PNode pNewRoot = NULL;
	int len = 0;
	len = strlen(array);

	CreateBinaryTree(&pRoot, array, len, '#');
	pNewRoot = CopyBinaryTree(pRoot);
}

void TestTraversalBinaryTree()
{
	char array[] = "ABD###CE##F";
	PNode pRoot = NULL;
	PNode pNewRoot = NULL;
	int len = 0;
	len = strlen(array);

	CreateBinaryTree(&pRoot, array, len, '#');
	pNewRoot = CopyBinaryTree(pRoot);

	TraversalBinaryTree(pRoot);
	printf("\n");
	TraversalBinaryTree(pNewRoot);
}

void TestDestroyBinaryTree()
{
	char array[] = "ABD###CE##F";
	PNode pRoot = NULL;
	PNode pNewRoot = NULL;
	int len = 0;
	len = strlen(array);

	CreateBinaryTree(&pRoot, array, len, '#');
	DestroyBinaryTree(pRoot);
}
int main()
{
	//TestCreateBinaryTree();
	//TestCopyBinaryTree();
	//TestTraversalBinaryTree();
	TestDestroyBinaryTree();
	return 0;
}
