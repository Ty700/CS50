#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <stdint.h>

typedef struct {
	char* name;
	int votes;
} Candidate;

int generate_candidate_list(Candidate** list, uint32_t list_size, char *names[]);

void get_amount_of_voters(uint32_t** p_amount_of_voters);

void collect_ballots(Candidate** list, uint32_t list_size, uint32_t voter_count);

int get_winner(Candidate** list, uint32_t list_size);

#endif /*CANDIDATE_H*/
