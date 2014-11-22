/****************************************************************************
Student Name: Tim Kelly                       Student Number:  0755233                           
****************************************************************************/

#include "AVLAdt.h"

int main(){

	treeRoot theRoot;
	theRoot = createTree();

	char * testString = malloc(sizeof(char)*50);
	strcpy(testString, "fat");

	char * testString1 = malloc(sizeof(char)*50);
	strcpy(testString1, "cat");

	char * testString2 = malloc(sizeof(char)*50);
	strcpy(testString2, "hat");

	char * testString3 = malloc(sizeof(char)*50);
	strcpy(testString3, "zoo");

	char * testString4 = malloc(sizeof(char)*50);
	strcpy(testString4, "apple");

	char * testString5 = malloc(sizeof(char)*50);
	strcpy(testString5, "");

	char * testString6 = malloc(sizeof(char)*50);
	strcpy(testString6, "xylophone");


	theRoot = insert(theRoot, testString2);
	theRoot = insert(theRoot, testString1);
	theRoot = insert(theRoot, testString);
	printf("\n Inserting apple\n");
	theRoot = insert(theRoot, testString4);
	/*theRoot = insert(theRoot, testString6);
	*/
	




/*
	node * testSearch;
	testSearch = search(theRoot, "cat");

	printVal(testSearch);

	printf("\n The height is : %d", height(testSearch));

*/



	printf("\n");

	printPreOrder(theRoot);

	printf("\n");
	/*
	printPostOrder(theRoot);

	printf("\n");

	printInOrder(theRoot);
*/


	return(0);
}

