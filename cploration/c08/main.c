#include "parser.h"
#include "error.h"
#include "symtable.h"

int main(int argc, const char *argv[]){

    if (argc != 2) {
        // incorrect number of arguments
        exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);        
    }  

    FILE *file = fopen(argv[1], "r");

    if(file == NULL){        
        exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
    }

    parse(file);

    fclose(file);

    return 0;
}