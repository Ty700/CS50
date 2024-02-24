#include "candidate.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int generate_candidate_list(Candidate** list, int list_size, char *names[]){ 
	
	//Creates buffer to house candidates and inits name to be argv index
	for(int i = 0; i < list_size; i++){
		list[i] = (Candidate *)malloc(sizeof(Candidate));
		if(list[i] == NULL){
			fprintf(stderr, "Error allocating memory for list.\n");
			return -1;
		}
		list[i]->name = names[i + 1];
		list[i]->votes = 0;
	}

	#ifdef DEBUG
		for(int i = 0; i < list_size; i++){
			fprintf(stdout, "Candidate %d Name: %s\n", i+1, list[i]->name);
			fprintf(stdout, "Candiate Vote Count: %d\n", list[i]->votes);
		}
	#endif /*DEBUG*/

	#ifndef DEBUG
        for(int i = 0; i < list_size; i++){
            printf("Candidate %d Name: %s\n", i+1, list[i]->name);
        }
	#endif /*DEBUG*/

	return 0;
}


int get_amount_of_voters(){
	char *buffer = (char *)malloc(10);
	int num = 0;

	fprintf(stdout, "How many voters?\n");

	fgets(buffer, 10, stdin);
 	
	sscanf(buffer, "%d", &num);

#ifdef DEBUG
	fprintf(stdout, "Vote amount: %d\n", num);
#endif /*DEBUG*/
	
	free(buffer);
	return num;	
}

//TODO: ADD ERROR CHECKING
void collet_ballets(Candidate** list, const int list_size, const uint32_t amount_of_voters){
	for(int i = 0; i < amount_of_voters; i++){

		//TODO: DYNAMICALLY ALLOC SIZE OF NAME
		char *name = (char *)calloc(32, sizeof(char));
		
		fprintf(stdout, "Which candidate: ");
			fgets(name, 32, stdin);
			fflush(stdin);

		//Changes the \n to \0
		name[strcspn(name, "\n")] = '\0';

		#ifdef DEBUG
			fprintf(stdout, "You entered: %s\n", name);
		#endif /*DEBUG*/

		//TODO: FIND CANDIDATE IN LIST AND ADD ONE TO VOTE
		//ERROR CHECK FOR IF CANDIDATE IS NOT IN LIST
		
		for(int i = 0; i < list_size; i++)
		{
			if((strncmp(name, list[i]->name, strlen(name))) == 0)
			{
				list[i]->votes += 1;

				#ifdef DEBUG
					fprintf(stdout, "%s == %s\n", name, list[i]->name);
					fprintf(stdout, "Found %s at: %d index\n",name, i);
					fprintf(stdout, "%s's vote count: %d\n", name, list[i]->votes);
				#endif /*DEBUG*/

				break;
			}

			if((i+1) == list_size)
			{
				fprintf(stdout, "Error: Invalid Candidate Name.\n");
				collet_ballets(list, list_size, i);
			}

		}		

		#ifdef DEBUG
			fprintf(stdout, "Current Value of I: %d\n", i);
		#endif

		free(name);
	}
}






















