#include <stdint.h>

#define NUM_PREDEFINED_SYMBOLS 23

typedef struct predefined_symbol{
    char *name;
    int16_t address;
}predefined_symbol;


typedef enum symbol_ID{
    SYM_R0 = 0,
    SYM_R1,
    SYM_R2,
    SYM_R3,
    SYM_R4,
    SYM_R5,
    SYM_R6,
    SYM_R7,
    SYM_R8,
    SYM_R9,
    SYM_R10,
    SYM_R11,
    SYM_R12,
    SYM_R13,
    SYM_R14,
    SYM_R15,
    SYM_SP = 0,
    SYM_LCL = 1,
    SYM_ARG = 2,
    SYM_THIS = 3,
    SYM_THAT = 4,
    SYM_SCREEN = 16384,
    SYM_KBD = 24576,
}symbol_ID;

static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {
    {"R0", SYM_R0},
    {"R1", SYM_R1}, 
    {"R2", SYM_R2},
    {"R3", SYM_R3},
    {"R4", SYM_R4},
    {"R5", SYM_R5},
    {"R6", SYM_R6},
    {"R7", SYM_R7},
    {"R8", SYM_R8},
    {"R9", SYM_R9},
    {"R10", SYM_R1},
    {"R11", SYM_R1},
    {"R12", SYM_R1},
    {"R13", SYM_R1},
    {"R14", SYM_R1},
    {"R15", SYM_R1},
    {"SP", SYM_SP},
    {"LCL", SYM_LCL},
    {"ARG", SYM_ARG},
    {"THIS", SYM_THIS},
    {"THAT", SYM_THAT},
    {"SCREEN", SYM_SCREEN},
    {"KBD", SYM_KBD}
};