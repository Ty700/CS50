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

	Candidate **list = (Candidate **)malloc(sizeof(Candidate) * LIST_SIZE); 
	
	if(generate_candidate_list(list, LIST_SIZE, argv)){
		//Something failed in generate_candidate_list
		return -1;
	}

	uint32_t voter_count = get_amount_of_voters();	
	
	if(!voter_count){
		fprintf(stderr, "No voters.\n");
		return -1;
	}	

	collet_ballets(list, LIST_SIZE, voter_count);

	

	//Clean up
	for(int i = 0; i < LIST_SIZE; i++){
		free(list[i]);
	}

	free(list);
	return 0;

}
