#include <stdio.h>
#include <stdlib.h>

#include "candidate.h"

#define LIST_SIZE (argc - 1)
//TODO: ADD SORTING ALGO TO CANDIDATE LIST TO AVOID SEARCHING FOR NAME IN GET_VOTES

int main(int argc, char *argv[]){
	
	Candidate **list = (Candidate **)malloc(sizeof(Candidate) * LIST_SIZE); 
	
	int ret_status = generate_candidate_list(list, LIST_SIZE, argv);
	
	if(ret_status){
		//Something failed in generate_candidate_list
		return -1;
	}

	int vote_count = get_amount_of_voters();	
	
	if(!vote_count){
		fprintf(stderr, "No voters.\n");
		return -1;
	}	

	
	//Clean up
	for(int i = 0; i < LIST_SIZE; i++){
		free(list[i]);
	}

	free(list);
	return 0;

}
