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
