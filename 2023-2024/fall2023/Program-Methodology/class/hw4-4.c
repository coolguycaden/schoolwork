#include <stdio.h>
#include <time.h> // for seeding random number
#include <stdlib.h> // for srand and rand

/*     MY ANALYSIS OF THE PROGRAM
 *
 *      From my runs, there were a few specific words that very difficult
 *      to make a sentence that makes sense if there were present
 *      These words are: any, under, and town
 *
 *      For the most part, most sentences generated make no sense, mostly due
 *      to the "reasonability" of a noun doing an action (verb)
 *      For example, a town cannot jump or walk, and thus any sentence with town
 *      doing an action makes no sense
 *      Furthermore, most people cannot walk, skip, or run underneath someone
 *      unless their is a elevation difference, like being on a bridge
 *
 *      To conclude, this program sucks at making reasonable sentences 
 *
 */

int main(){
	srand(time(NULL));

	char * articles[] = {"the", "a", "one", "some", "any"};
	char * nouns[] = {"boy", "girl", "dog", "town", "car"};
	char * verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
	char * prepositions[] = {"to", "from", "over", "under", "on"};

	//article, noun, verb, prep, articl, noun

	int x;
	for(x = 0; x < 20; x++){
		//each holds a random number		
		int randomNum1 = rand() % 5;
		int randomNum2 = rand() % 5;
		int randomNum3 = rand() % 5;
		int randomNum4 = rand() % 5;
		int randomNum5 = rand() % 5;
		int randomNum6 = rand() % 5;

		printf("%s %s %s %s %s %s\n", articles[randomNum1], nouns[randomNum2], verbs[randomNum3], 
					      prepositions[randomNum4], articles[randomNum5], nouns[randomNum6] );
	}
}
