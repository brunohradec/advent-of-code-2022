#include <stdio.h>
#include <stdlib.h>

#define LINE_BUFFER_SIZE 255
#define MAX_SUMS_NUM 3

void sort(int* arr, int size) {
    int i, j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main(void) {
    char line_buff[LINE_BUFFER_SIZE];
    int max_sums[MAX_SUMS_NUM] = {};
    
    int max_total = 0;
    int crr_sum = 0;
    int crr_cal = 0;
    int i;
    
    FILE* input;

    input = fopen("./input.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line_buff, sizeof line_buff, input) != NULL) {
        if (line_buff[0] == '\n') {
            sort(max_sums, MAX_SUMS_NUM);
            
            if (crr_sum > max_sums[0]) {
                max_sums[0] = crr_sum;
            }

            crr_sum = 0;
        } else {
            sscanf(line_buff, "%d", &crr_cal);
            crr_sum += crr_cal;
        }
    }

    for (i = 0; i < MAX_SUMS_NUM; i++) {
        max_total += max_sums[i];
    }

    printf("max three sum: %d\n", max_total);

    fclose(input);

    return 0;
}