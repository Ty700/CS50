#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <stdint.h>

typedef struct {
	char* name;
	int votes;
} Candidate;

int generate_candidate_list(Candidate** list, int list_size, char *names[]);

int get_amount_of_voters();

void collet_ballets(Candidate** list, const int list_size, const uint32_t amount_of_voters);

#endif /*CANDIDATE_H*/
