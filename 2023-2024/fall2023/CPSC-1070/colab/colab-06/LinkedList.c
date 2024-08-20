#include "LinkedList.h"

void printList(struct node * head){
	struct node * temp = head;
	struct node * previousNode;
	int count = 1;
	if(head->nextNode == NULL){
		printf("You've entered the following node: %s", temp->word);
		free(head->word);
	} else {

		printf("You've entered the following nodes:");
		while(temp->nextNode != NULL){
			if(count > 1){
				printf(",");
			}
			count++;
			printf(" %s", temp->word);
			previousNode = temp;
			temp = temp->nextNode;
			free(previousNode->word);
			free(previousNode);
		}

		if(count > 2){
			printf(", and %s", temp->word);
		} else {
			printf(" and %s", temp->word);
		}
		free(temp->word);
	}
	
	free(temp);
};

struct node* makeList(){
	struct node * newNode = malloc(sizeof(struct node));
	newNode->nextNode = NULL;
	newNode->word = NULL;
	return newNode;
}

void insert(struct node * head, char * newWord){
	struct node * temp = head;
	int count = 1;
	while(temp->nextNode != NULL){
		//printf("this node was %s,", temp->word);
		temp = temp->nextNode;
		count++;
	}
	//printf("adding %d node \n", count);
	temp->nextNode = makeList();
	temp->nextNode->word = newWord;
	//printf("new node, and %s\n", temp->nextNode->word);
}

