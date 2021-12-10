#ifndef __PARSER_H__
#define __PARSER_H__

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2)
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTION MAX_HACK_ADDRESS
#define MAX_INSTRUCTION_COUNT 30000

typedef int16_t hack_addr;
typedef int16_t opcode; 


typedef struct a_instruction{
    union {
        hack_addr address;
        char *label;
    }addr_or_label;
    bool is_addr;
} a_instruction;

char *strip(char *s);
char *extract_label(char *line);
void add_predefined_symbols();
bool parse_A_instruction(const char *line, a_instruction *instr);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);

enum instr_type{
    Invalid = -1,
    A_Type,
    C_Type,
};

typedef struct c_instruction{
    opcode a:1;
    opcode comp:7;
    opcode dest:4;
    opcode jump:4;
} c_instruction;



typedef struct instruction{
    union {
        c_instruction c;
        a_instruction a;
    } instr;
    enum instr_type type;
} instruction;


int parse(FILE * file, instruction *instructions);
void parse_C_instruction(char *line, c_instruction *instr);
void assemble(const char * file_name, instruction* instructions, int num_instructions);
opcode instruction_to_opcode(c_instruction instr);
#endif