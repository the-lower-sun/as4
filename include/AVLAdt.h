/****************************************************************************
Student Name: Tim Kelly                       Student Number:  0755233                           
****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this list structure is capable of storing istrings only*/
/* struck of the listnode*/
typedef struct treeNode {
	char nodeValue[50];
	struct treeNode * leftNode;
	struct treeNode * rightNode;
	struct treeNode * rootNode;
	int height;
	int count;
}node;


typedef node * treeRoot;

node * createTree();
void printVal(node * toPrint);
node * search(node * root, char * searchVal);
node * insert(node * root, char * newValue);
/*int deleteNode(node * root, char * toDelete);*/
int maxHeight(node * root);
int checkBalance(node * root);
node * leftRotate(node * root);
node * rightRotate(node * root);

int height(node * root);

node * leftChild(node * root);

node * addLeft(node * theNode, char * toAdd);
node * addRight(node * theNode, char * toAdd);
node * initNode(char * toAdd);
void updateVal(node * toUpdate, char * newVal);
int isInternal(node * toCheck);
int isExternal(node * toCheck);
void printPreOrder(treeRoot root);
void printPostOrder(treeRoot root);
void printInOrder(treeRoot root);

