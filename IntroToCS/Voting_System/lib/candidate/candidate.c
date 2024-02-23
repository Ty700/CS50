#include "candidate.h"
#include <stdlib.h>
#include <stdio.h>

int generate_candidate_list(Candidate** list, int list_size, char *names[]){ 
	for(int i = 0; i <= list_size; i++){
		list[i] = (Candidate *)malloc(sizeof(Candidate));
		if(list[i] == NULL){
			fprintf(stderr, "Error allocating memory for list.\n");
			return -1;
		}
		list[i]->name = names[i + 1];
	}

#ifdef DEBUG
        for(int i = 0; i < list_size; i++){
                printf("Candidate %d Name: %s\n", i+1, list[i]->name);
        }
#endif /*DEBUG*/

	return 0;
}


int get_amount_of_voters(){
	char *buffer = (char *)malloc(10);;
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

void get_votes(Candidate** list, int amount_of_votes){

	for(int i = 0; i < amount_of_votes; i++){
		
	}

}






















