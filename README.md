# BinaryTreeNode-
//二叉树


//BinaryTree.h


#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#pragma once

typedef char DataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _pLeft;
	struct BinaryTreeNode* _pRight;
	DataType _data;

}Node, *PNode;

//二叉树的创建
void _CreateBinaryTree(PNode* pRoot, char array[], int size, char invalid, int* index);
void CreateBinaryTree(PNode* pRoot, char array[], int size, char invalid);
PNode BuyBinaryTreeNode(DataType data);
PNode CopyBinaryTree(PNode pRoot);
void TraversalBinaryTree(PNode pRoot);
void DestroyBinaryTree(PNode* pRoot);

#endif //__BINARYTREE_H__


//BinaryTree.c
#include "BinaryTree.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

PNode BuyBinaryTreeNode(DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(pNewNode);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}

void _CreateBinaryTree(PNode* pRoot, char array[], int size, char invalid, int* index)
{
	assert(pRoot);
	if ((*index)<size && invalid != array[*index])
	{
		*pRoot = BuyBinaryTreeNode(array[*index]);

		++(*index);
		_CreateBinaryTree(&(*pRoot)->_pLeft, array, size, invalid, index);

		++(*index);
		_CreateBinaryTree(&(*pRoot)->_pRight, array, size, invalid, index);
	}
}

void CreateBinaryTree(PNode* pRoot, char array[], int size, char invalid)
{
	int index = 0;
	_CreateBinaryTree(pRoot, array, size, invalid, &index);
}

PNode CopyBinaryTree(PNode pRoot)
{
	PNode pNewRoot = NULL;
	if (pRoot)
	{
		pNewRoot = BuyBinaryTreeNode(pRoot->_data);

		if (pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinaryTree(pRoot->_pLeft);

		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinaryTree(pRoot->_pRight);

	}

	return pNewRoot;
}

void TraversalBinaryTree(PNode pRoot)
{
	if (pRoot)
	{
		printf("%c ",pRoot->_data);

		TraversalBinaryTree(pRoot->_pLeft);
		TraversalBinaryTree(pRoot->_pRight);

	}
}

void DestroyBinaryTree(PNode pRoot)
{
	if (pRoot)
	{
		if (pRoot->_pLeft)
			DestroyBinaryTree(pRoot->_pLeft);
		if (pRoot->_pRight)
			DestroyBinaryTree(pRoot->_pRight);
	}
	free(pRoot);
	pRoot = NULL;
}



//test.c

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
