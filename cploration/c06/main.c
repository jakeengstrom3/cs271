#include "parser.h"

int main(int argc, const char *argv[]){

    if(argc != 2){
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if(file == NULL){
        printf("Unable to read file");
        exit(EXIT_FAILURE);
    }

    parse(file);

    fclose(file);

    return 0;
}