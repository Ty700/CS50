#include "candidate.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

static void clear_stream(){
	int c;

	while((c = getchar()) != '\n' && c != EOF){}
}

int generate_candidate_list(Candidate** list, uint32_t list_size, char *names[])
{ 
	
	//Creates buffer to house candidates and inits name to be argv index
	for(int i = 0; i < list_size; i++)
	{
		list[i] = (Candidate *)malloc(sizeof(Candidate));
		
		if(list[i] == NULL)
		{
			fprintf(stderr, "Error allocating memory for list.\n");
			return -1;
		}
		
		list[i]->name = names[i + 1];
		list[i]->votes = 0;
	}

	#ifdef DEBUG
		for(int i = 0; i < list_size; i++)
		{
			fprintf(stdout, "Candidate %d Name: %s\n", i+1, list[i]->name);
			fprintf(stdout, "Candiate Vote Count: %d\n", list[i]->votes);
		}
	#endif /*DEBUG*/

	#ifndef DEBUG
        for(int i = 0; i < list_size; i++)
		{
            printf("Candidate %d Name: %s\n", i+1, list[i]->name);
        }
	#endif /*DEBUG*/

	return 0;
}

void get_amount_of_voters(uint32_t** p_amount_of_voters)
{
	fprintf(stdout, "How many voters?\n");

	scanf("%u", *p_amount_of_voters);
	clear_stream();

	#ifdef DEBUG
		fprintf(stdout, "Vote amount: %d\n", **p_amount_of_voters);
	#endif /*DEBUG*/	
}

void collect_ballots(Candidate** list, uint32_t list_size, uint32_t voter_count) 
{
    char voter_choice[256]; // Buffer to store voter's choice

    printf("Voting has begun. Please enter the name of your chosen candidate.\n");

    for (uint32_t i = 0; i < voter_count; ++i)
	{
        printf("Voter %u: ", i + 1);
		
        if (fgets(voter_choice, sizeof(voter_choice), stdin))
		{	

			#ifdef DEBUG
				fprintf(stdout, "Entered Candidate: %s\n", voter_choice);
			#endif /*DEBUG*/

            // Remove newline character if present
            voter_choice[strcspn(voter_choice, "\n")] = 0;

            // Search for the candidate and increment votes if found
            int found = 0;

            for (uint32_t j = 0; j < list_size; ++j)
			{	
				#ifdef DEBUG
					fprintf(stdout, "%s\n", list[j]->name);
				#endif

                if (strncmp(list[j]->name, voter_choice, sizeof(voter_choice)) == 0)
				{
                    list[j]->votes++;
                    found = 1;

					#ifdef DEBUG
						fprintf(stdout, "%s Vote Count: %d\n", list[j]->name, list[j]->votes);

                    #endif /*DEBUG*/
					break;

                }
            }

            if (!found)
			{
                printf("Candidate not found, please try again.\n");
                i--;
            }
		}
    }
}

int get_winner(Candidate** list, uint32_t list_size){
	//Finds winnder of candidate list in a destructive way
	//Error with tie logic
	uint32_t tie_count = 0;

	for(int i = 1; i < list_size; i++){		
		if(list[0]->votes < list[i]->votes){
			list[0]->name = list[i]->name;
			tie_count = 0;
		}

		if(list[0]->votes == list[i]->votes){
			list[tie_count + 1]->name = list[i]->name;
			list[tie_count + 1]->votes = list[i]->votes;

			tie_count++;
		}
	}

	if(tie_count){
		return tie_count;
	}

	return 0;
}