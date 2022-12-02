#include <stdio.h>
#include <stdlib.h>

#define ROCK 'A'
#define PAPER 'B'
#define SCISSORS 'C'

#define LOSS 'X'
#define DRAW 'Y'
#define WIN 'Z'

#define ROCK_VALUE 1
#define PAPER_VALUE 2
#define SCISSORS_VALUE 3

#define DRAW_VALUE 3
#define WIN_VALUE 6

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

        if (me == LOSS) {
            if (opponent == ROCK) {
                round_result += SCISSORS_VALUE;
            } else if (opponent == PAPER) {
                round_result += ROCK_VALUE;
            } else if (opponent == SCISSORS) {
                round_result += PAPER_VALUE;
            }
        } else if (me == DRAW) {
            round_result += DRAW_VALUE;
            if (opponent == ROCK) {
                round_result += ROCK_VALUE;
            } else if (opponent == PAPER) {
                round_result += PAPER_VALUE;
            } else if (opponent == SCISSORS) {
                round_result += SCISSORS_VALUE;
            }
        } else if (me == WIN) {
            round_result += WIN_VALUE;
            if (opponent == ROCK) {
                round_result += PAPER_VALUE;
            } else if (opponent == PAPER) {
                round_result += SCISSORS_VALUE;
            } else if (opponent == SCISSORS) {
                round_result += ROCK_VALUE;
            }
        }

        game_result += round_result;
    }

    printf("game result: %d\n", game_result);

    fclose(input);

    return 0;
}