#include "candidate.h"

void generate_candidate_list(Candidate* list[], int list_size, char *names[]){ 
	for(int i = 0; i <= list_size; i++){
		list[i]->name = names[i + 1];
	}
}

