#include <stdio.h>
#include <stdlib.h>

#define LINE_BUFFER_SIZE 255

int main(void) {
    char line_buff[LINE_BUFFER_SIZE];

    int max_sum = 0;
    int crr_sum = 0;
    int crr_cal = 0;
    
    FILE* input;

    input = fopen("./input.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line_buff, sizeof line_buff, input) != NULL) {
        if (line_buff[0] == '\n') {
            if (crr_sum > max_sum) {
                max_sum = crr_sum;
            }
            crr_sum = 0;
        } else {
            sscanf(line_buff, "%d", &crr_cal);
            crr_sum += crr_cal;
        }
    }
    
    printf("max sum: %d\n", max_sum);

    fclose(input);

    return 0;
}