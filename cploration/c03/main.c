#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_LINE_LENGTH  200
int main(int argc, const char *argv[]){

    printf("Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);

    FILE *fin = fopen(argv[1], "r" );
    perror("Unable to open file!");
    exit(EXIT_FAILURE);

    char out_file[MAX_LINE_LENGTH];
    FILE *fout = fopen(out_file, "w+");

    char line[MAX_LINE_LENGTH];
    unsigned int line_num = 0;

    while(fgets(line, sizeof(line), fin)){
        line_num++;
        printf("[Line Num: %u] %s", line_num, line);
        fprintf(fout, "%s", line);
    }
    fclose(fin); fclose(fout);

    return 0;
}