#include <stdio.h>
#include <stdlib.h>

#define OPPONENT_ROCK 'A'
#define OPPONENT_PAPER 'B'
#define OPPONENT_SCISSORS 'C'

#define ME_ROCK 'X'
#define ME_PAPER 'Y'
#define ME_SCISSORS 'Z'

#define ROCK_VALUE 1
#define PAPER_VALUE 2
#define SCISSORS_VALUE 3

#define DRAW_VALUE 3
#define WIN_VALUE 6

char translate_opponent(char opponent) {
    switch(opponent) {
        case OPPONENT_ROCK: return ME_ROCK;
        case OPPONENT_PAPER: return ME_PAPER;
        case OPPONENT_SCISSORS: return ME_SCISSORS;
    }

    return 0;
}

int main(void) {
    char opponent;
    char me;

    int round_result = 0;
    int game_result = 0;

    FILE* input;

    input = fopen("./input.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(input, " %c %c", &opponent, &me) != EOF) {
        round_result = 0;

        if (me == ME_ROCK) {
            round_result += ROCK_VALUE; 
            if (opponent == OPPONENT_SCISSORS) {
                round_result += WIN_VALUE;
            }
        } else if (me == ME_PAPER) {
            round_result += PAPER_VALUE; 
            if (opponent == OPPONENT_ROCK) {
                round_result += WIN_VALUE;
            }
        } else if (me == ME_SCISSORS) {
            round_result += SCISSORS_VALUE; 
            if (opponent == OPPONENT_PAPER) {
                round_result += WIN_VALUE;
            }
        }

        if (me == translate_opponent(opponent)) {
            round_result += DRAW_VALUE;
        }

        game_result += round_result;
    }

    printf("game result: %d\n", game_result);

    fclose(input);

    return 0;
}