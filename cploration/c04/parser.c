#include "parser.h"

void parse(FILE * file){
    char line[MAX_LINE_LENGTH] = "";

    while(fgets(line, sizeof(line), file)){
        strip(line);
        if(*line == '\0'){
            continue;
        }
        else{
            printf("%s\n", line);
        }
    }
}

char *strip(char *s){
    char s_new[sizeof(s) + 1] = "";
    int i = 0;

    for(char *s2 = s; *s2; s2++){
        if(*s2 == '/' && *(s2 + 1) == '/'){
            break;
        }
        else if (!isspace(*s2)){
            s_new[i++] = *s2;
        }
    }
    //Only adds null character to non-empty lines
    s_new[i] = '\0';
    stpcpy(s, s_new);
    return s;
}
