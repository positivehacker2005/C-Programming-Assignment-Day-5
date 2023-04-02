#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("error_log.txt", "w");
    char line[MAX_LINE_LENGTH];

    if (input_file == NULL) {
        printf("Error: Failed to open input file\n");
        exit(1);
    }

    if (output_file == NULL) {
        printf("Error: Failed to open output file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        if (strstr(line, "error") != NULL) {
            fputs(line, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);

    
    FILE *error_log_file = fopen("error_log.txt", "r");

    if (error_log_file == NULL) {
        printf("Error: Failed to open error log file\n");
        exit(1);
    }

    printf("Contents of error log:\n");

    while (fgets(line, MAX_LINE_LENGTH, error_log_file) != NULL) {
        printf("%s", line);
    }

    fclose(error_log_file);

    return 0;
}
