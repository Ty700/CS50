#ifndef CANDIDATE_H
#define CANDIDATE_H

typedef struct {
	char* name;
	int votes;
} Candidate;

int generate_candidate_list(Candidate** list, int list_size, char *names[]);

int get_amount_of_voters();

void get_votes(Candidate** list, int amount_of_votes);

#endif /*CANDIDATE_H*/
