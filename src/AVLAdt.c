/****************************************************************************
Student Name: Tim Kelly                        Student Number:  0755233                          
****************************************************************************/


#include "AVLAdt.h"



/*function to create the tree*/
node * createTree (){
	node *newNode = malloc(sizeof(node));
	newNode->rootNode = NULL;
	newNode->height = 1;

	char * testString = malloc(sizeof(char)*50);
	strcpy(testString, "");

	newNode->leftNode = initNode(testString);
	newNode->rightNode = initNode(testString);

	newNode->height = 0;

	return newNode;
}



void printVal(node * toPrint){
	printf("\n node value: %s\n", toPrint->nodeValue);
}

node * search(node * root, char * searchVal){
	if(isExternal(root) == 1) return NULL;
	if(strcmp(searchVal,root->nodeValue)<0){
		return(search(root->leftNode,searchVal));
	}
	else if(strcmp(searchVal,root->nodeValue)==0){
		return(root);
	}
	else {
		return(search(root->rightNode,searchVal));
	}
	
}


/*function to insert a new node into tree and rebalance if necessary*/
node * insert(node * root, char * newValue){

	if(strcmp(root->nodeValue,"") == 0){

		printf("\n actually inserting value: %s \n",newValue);

		strcpy(root->nodeValue, newValue);
		char * testString = malloc(sizeof(char)*50);
		strcpy(testString, "");

		root->leftNode = initNode(testString);
		root->rightNode = initNode(testString);

		root->height = 1;
		return (root);
	}
	else{
		if(strcmp(newValue,root->nodeValue)<0){
			insert(root->leftNode, newValue);
		}
		else if(strcmp(newValue,root->nodeValue)>0){
			insert(root->rightNode, newValue);
		}
		else{
			root->count++;
			return (root);
		}
	}

	root-> height = (maxHeight(root) +1);

	int balance = checkBalance(root);
	printf("\nChecking for imbalance, balance = %d. ", balance);
	
	if (balance > 1 && (strcmp(root->leftNode->leftNode->nodeValue, "") != 0)){

		printf("rightRotate");
		return rightRotate(root);
	}

	if (balance < -1 && (strcmp(root->rightNode->rightNode->nodeValue, "") != 0)){

		printf("leftRotate");
		return leftRotate(root);
	}

	if (balance > 1 && (strcmp(root->leftNode->leftNode->nodeValue, "") == 0)){

		printf("left right");
		root->leftNode = leftRotate(root->leftNode);
		return rightRotate(root);
	}

	if (balance < -1 && (strcmp(root->rightNode->rightNode->nodeValue, "") == 0)){

		printf("right left");
		root->rightNode = rightRotate(root->rightNode);
		return leftRotate(root);
	}


	return root;

}



node * rightRotate(node * root){

	node * middle = root->leftNode;
	node * empty = root->rightNode;

	middle->rightNode = root;
	root->leftNode = empty;

	root->height = maxHeight(root)+1;
	middle->height = maxHeight(middle)+1;

	return middle;
}



node * leftRotate(node * root){

	node * middle = root->rightNode;
	node * empty = root->leftNode;

	middle->leftNode = root;
	root->rightNode = empty;

	root->height = maxHeight(root)+1;
	middle->height = maxHeight(middle)+1;

	return middle;
}



int checkBalance(node * root){

	if (root == NULL) return 0;

	return (height(root->leftNode) - height(root->rightNode));
}

int height(node * root){
	if (root != NULL){
		return root->height;
	}
	else return 0;
}


int maxHeight(node * root){

	if(root == NULL) return 0;

	if(root->rightNode->height > root->leftNode->height) return root->rightNode->height;

	else return root->leftNode->height;
}












/*add to left node*/
node * addLeft(node * theNode, char * toAdd){
	node * newNode = initNode(toAdd);
	theNode->leftNode = newNode;
	newNode->rootNode = theNode;
	return newNode;
}

/*add to right node*/
node * addRight(node * theNode, char * toAdd){
	node * newNode = initNode(toAdd);
	theNode->rightNode = newNode;
	newNode->rootNode = theNode;
	return newNode;
}








/*initialize a node*/	
node * initNode(char * toAdd){
	node * newNode = malloc(sizeof(node));
	strcpy(newNode->nodeValue, toAdd);
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->height = 0;
	return newNode;
}

void updateVal(node * toUpdate, char * newVal){
	if (toUpdate != NULL && newVal != NULL){
		strcpy(toUpdate->nodeValue, newVal);
	}
}

int isInternal(node * toCheck){
	if(toCheck != NULL){
		if(toCheck->leftNode != NULL || toCheck->rightNode != NULL){
			return(1);
		}
		else return(0);
	}
	else return(-1);
}

int isExternal(node * toCheck){
	if(toCheck != NULL){
		if(toCheck->leftNode == NULL && toCheck->rightNode == NULL){
			return(1);
		}
		else return(0);
	}
	else return(-1);
}

/*print list*/
void printPreOrder(treeRoot root){
	if(root != NULL){
		if(strcmp(root->nodeValue,"") != 0) printf("%s, ", root->nodeValue);
		printPreOrder(root->leftNode);
		printPreOrder(root->rightNode);
	}
}


void printPostOrder(treeRoot root){
	if(root != NULL){
		printPostOrder(root->leftNode);
		printPostOrder(root->rightNode);
		printf("%s, ",root->nodeValue);
	}
}

void printInOrder(treeRoot root){
	if(root != NULL){
		if(isInternal(root) == 1){
			printInOrder(root->leftNode);
		}
		if(strcmp(root->nodeValue,"") != 0) printf("%s, ", root->nodeValue);
		if (isInternal(root) == 1){
			printInOrder(root->rightNode);
		}
	}
}

void displayTree(treeRoot root){
	if(root != NULL){
		
	}
}