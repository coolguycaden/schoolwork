#include "LinkedList.h"
#include <string.h>
#include <stdbool.h>

int main(){

	struct node * head = makeList();
	char * userWord = NULL;
	bool done = false;
	/*userWord = (char *) malloc(100);
	scanf("%s", userWord);
	head->word = userWord;
	printf("word is %s\n", head->word);
	head->nextNode = makeList();
	//free(userWord);
	userWord = (char *) malloc(100);
	printf("last word is %s\n", head->word);
	
	scanf("%s", userWord);
	head->nextNode->word = userWord;
	printf("word is %s\n", head->nextNode->word);
	printf("last word is %s\n", head->word);
	*/

	do {
		//userWord = NULL//(char *) malloc(100);
		printf("Enter a word or phrase, or -99 to end: ");
		
		size_t size = 0;
		getline(&userWord, &size, stdin);
		userWord[strlen(userWord) - 1] = '\0';

		if(strstr(userWord, "-99") != NULL && strstr(userWord, "-999") == NULL){
		//	puts("printing");
			printList(head);
			done = true;
		} else if(head->word == NULL){	
			//puts("first");
			//printf("head mmry %p\n", head);
			head->word = userWord;
			//head->nextNode = makeList();
			//printf("first head is %s\n", head->word);
		} else {
			
			//head->nextNode = makeList();
			//puts("insert");
			//printf("head is %s\n", head->word);
			insert(head, userWord);	
			//printf("user input is %s\n", userWord);
			//head->word = userWord;//(char *) malloc(sizeof(char) * (strlen(userWord) + 1));
			//head->word = userWord;
			//printf("%s\n", head->word);
		}
	} while (!done); 
	
	printf("\n");
	//head->word = "rizzlybear";
	//printf("%s\n", head->word);
}
