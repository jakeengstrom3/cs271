#include "parser.h"
#include "error.h"
#include "symtable.h"
#include "hack.h"

int parse(FILE * file, instruction *instructions){
    char line[MAX_LINE_LENGTH] = "";
    instruction instr;
    unsigned int line_num = 0;
    unsigned int instr_num = 0;


    add_predefined_symbols();
    symtable_display_table();
    

    while(fgets(line, sizeof(line), file)){
        ++line_num;
        if(instr_num > MAX_INSTRUCTION){ 
            exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTION + 1);
        }
        strip(line);
        if(*line == '\0'){
            continue;
        }
        else{
            char inst_type = '\0';
            if(is_Atype(line)){
                if (!parse_A_instruction(line, &instr.instr.a)){
                    exit_program(EXIT_INVALID_A_INSTR, line_num, line);
                }
                instr.type = A_Type;
                inst_type = 'A';
            }else if(is_label(line)){
                extract_label(line);
                
                if(!isalpha(line[0])){
                    exit_program(EXIT_INVALID_LABEL, line_num, line);
                }
                if(symtable_find(line) != NULL){
                    exit_program(EXIT_LABEL_ALREADY_EXISTS, line_num, line);
                }else{
                    symtable_insert(line, instr_num);
                }
                inst_type = 'L';
            }else {
                char tmp_line[MAX_LINE_LENGTH];
                strcpy(tmp_line, line);

                parse_C_instruction(tmp_line, &instr.instr.c);
                if (instr.instr.c.comp == COMP_INVALID){
                    exit_program(EXIT_INVALID_C_INSTR, line_num, line);
                }else if (instr.instr.c.dest == DEST_INVALID){
                    exit_program(EXIT_INVALID_C_INSTR, line_num, line);
                }else if (instr.instr.c.jump = JMP_INVALID){
                    exit_program(EXIT_INVALID_C_INSTR, line_num, line);
                }
                instr.type = C_Type;
                inst_type = 'C';   
            }
            printf("%c  %s\n", inst_type, line);   
        }
        instructions[instr_num++] = instr;    
    }
    return instr_num;
}

char *strip(char *s){
    char s_new[MAX_LINE_LENGTH] = "";
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
    strcpy(s, s_new);
    return s;
}   

void add_predefined_symbols(){
    for(int i = 0; i < NUM_PREDEFINED_SYMBOLS; i++){
        predefined_symbol symbol = predefined_symbols[i];
        symtable_insert(symbol.name, symbol.address);
    }
}

char *extract_label(char *line){
    memmove(line, line+1, strlen(line));
    line[strlen(line)- 1] = 0;
    return line;
}

bool is_Atype(const char *line){
    return line[0] == '@'; 
}

bool is_label(const char *line){
    return line[0] == '(' && line[strlen(line) - 1] == ')';
}

bool is_Ctype(const char *line){
    return !is_Atype(line) && !is_label(line);
}

bool parse_A_instruction(const char *line, a_instruction *instr){
    char *s = (char*) malloc(strlen(line));
    s = line + 1;
    char *s_end = NULL;
    long result = strtol(s, &s_end, 10);
    if(*s == *s_end){
        instr->addr_or_label.label = (char*) malloc(strlen(line));
        instr->is_addr = false;
    }else if(*s_end != 0){
        return false;
    }else{
        instr->addr_or_label.address = result;
    }
    return true;
}

void parse_C_instruction(char *line, c_instruction *instr){
    char *temp;
    char  *jump;
    char *dest;
    char *comp;
    char *a;
    temp = strtok(line, ";");
    jump = strtok(NULL, ";");

    dest = strtok(temp, "=");
    comp = strtok(NULL, "=");
    if(comp == NULL){
        comp = dest;
    }

    a = line[0] == "1" ? 1 : 0;

    instr->jump = str_to_jumpid(jump);
    instr->dest = str_to_destid(dest);
    instr->comp = str_to_compid(comp, a);
    instr->a = a;

    
}

