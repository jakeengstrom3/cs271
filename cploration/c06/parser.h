#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2)

typedef int16_t hack_addr;
typedef int16_t opcode; 

char *strip(char *s);
char *extract_label(char *line);
void parse(FILE * file);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);

enum instr_type{
    Invalid = -1,
    A_Type,
    B_Type,
};

typedef struct c_instruction{
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;
} c_instruction;

typedef struct a_instruction{
    union {
        hack_addr address;
        char *label;
    }addr_or_label;
    bool is_addr;
} a_instruction;

typedef struct instruction{
    union {
        c_instruction c;
        a_instruction a;
    } instr;
    enum instr_type type;
} instruction;
