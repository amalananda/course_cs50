#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
// Not the NAME of the candidate but the DATA type
candidate;

// Array of candidates  - defining array - not int or string but data type is candidate and name is candidates and population is max
candidate candidates[MAX];

// Number of candidates - variable is candidate count
int candidate_count;

// Function prototypes - takes name as input and outputs winner
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage - argc < 2 because you can't have just 2 (or less) candidates - must be at least 3
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates - this program uses 9 - it's arbitrary (for this program) but for the program required
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    // prompt user for number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote - if vote is not for a candidates
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO - write vote function - can't vote for NON candidate - loop through array of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // does name match candidate - if user name matches candidate - update totals. comparing STRINGS
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO - write return function - tell comp to count votes and return name - find max votes and print max vote person. First
    // need loop one by one
    int maxvotes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}