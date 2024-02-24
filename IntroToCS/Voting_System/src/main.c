#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "candidate.h"

#define LIST_SIZE (argc - 1)
//TODO: ADD SORTING ALGO TO CANDIDATE LIST TO AVOID SEARCHING FOR NAME IN GET_VOTES

int main(int argc, char *argv[]){
	
	if(argc < 2){
		fprintf(stderr, "Usage: ./VotingSystem <candidate_name_1> <candidate_name_2> ... <candidate_name_n>\n");
		return -1;
	}

	Candidate **list = (Candidate **)malloc(sizeof(Candidate *) * LIST_SIZE); 
	
	if(generate_candidate_list(list, LIST_SIZE, argv)){
		//Something failed in generate_candidate_list
		return -1;
	}

	uint32_t* voter_count = (uint32_t *)calloc(1, sizeof(*voter_count));
	
	if(voter_count == NULL){
		fprintf(stderr, "Error allocating memory for voter_count.\n");
		return -1;
	}

	get_amount_of_voters(&voter_count);	

	if(*voter_count == 0){
		fprintf(stderr, "No voters.");
		return -1;
	}
	
	collect_ballots(list, LIST_SIZE, *voter_count);

	int tie = get_winner(list, LIST_SIZE);

	if(tie){
		fprintf(stdout, "We have a tie between: ");

		for(int i = 0; i <= tie; i++){
			fprintf(stdout, "%s ", list[i]->name);
		}
		fprintf(stdout, "\n");
	} else {
		printf("Winner: %s\n", list[0]->name);
	}

	//Clean up
	for(int i = 0; i < LIST_SIZE; i++){
		free(list[i]);
	}

	free(list);
	return 0;

}
