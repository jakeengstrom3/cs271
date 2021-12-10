#include <stdint.h>

#define NUM_PREDEFINED_SYMBOLS 23
#define OPCODE_TO_BINARY(opcode) \
  (opcode & 0x8000 ? '1' : '0'), \
  (opcode & 0x4000 ? '1' : '0'), \
  (opcode & 0x2000 ? '1' : '0'), \
  (opcode & 0x1000 ? '1' : '0'), \
  (opcode & 0x800 ? '1' : '0'), \
  (opcode & 0x400 ? '1' : '0'), \
  (opcode & 0x200 ? '1' : '0'), \
  (opcode & 0x100 ? '1' : '0'), \
  (opcode & 0x80 ? '1' : '0'), \
  (opcode & 0x40 ? '1' : '0'), \
  (opcode & 0x20 ? '1' : '0'), \
  (opcode & 0x10 ? '1' : '0'), \
  (opcode & 0x8 ? '1' : '0'), \
  (opcode & 0x4 ? '1' : '0'), \
  (opcode & 0x2? '1' : '0'), \
  (opcode & 0x1? '1' : '0'), \
  

typedef struct predefined_symbol{
    char *name;
    int16_t address;
}predefined_symbol;

typedef enum jump_id{
    JMP_INVALID = -1,
    JMP_NULL,
    JGT,
    JEQ,
    JGE,
    JLT,
    JNE,
    JLE,    
    JMP,
}jump_id;

typedef enum dest_id{
    DEST_INVALID = -1,
    DEST_NULL,
    M,
    D,
    MD,
    A,
    AM,
    AD,
    AMD,
}dest_id;

typedef enum comp_id{
    COMP_INVALID = -1,
    COMP_0 = 42,
    COMP_1 = 63,
    COMP_NEG_1 = 58,
    COMP_D = 12,
    COMP_A = 48,
    COMP_NotD = 13,
    COMP_NotA = 49,
    COMP_NegD = 15,
    COMP_NegA = 51,
    COMP_DPlus1 = 31,
    COMP_APlus1 = 55,
    COMP_DMinus1 = 14,
    COMP_AMinus1 = 50,
    COMP_DPlusA = 2,
    COMP_DMinusA = 19,
    COMP_AMinusD= 7,
    COMP_DAndA = 0,
    COMP_DOrA = 21,
    COMP_M = 48,
    COMP_NotM = 49,
    COMP_NegM = 51,
    COMP_MPlus1 = 55,
    COMP_MMinus1 = 50,
    COMP_DPlusM = 2,
    COMP_DMinusM = 19,
    COMP_MMinusD = 7,
    COMP_DAndM = 0,
    COMP_DOrM = 21,
}comp_id;


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

static inline jump_id str_to_jumpid(const char *s){
    jump_id id = JMP_INVALID;

    if (s == NULL) {
        id = JMP_NULL;
    } else if (strcmp(s,"JGT") == 0 ){
        id = JGT;
    } else if (strcmp(s,"JEQ") == 0 ){
        id = JEQ;
    } else if (strcmp(s,"JGE") == 0 ){
        id = JGE;
    } else if (strcmp(s,"JLT") == 0 ){
        id = JLT;
    } else if (strcmp(s,"JNE") == 0 ){
        id = JNE;
    } else if (strcmp(s,"JLE") == 0 ){
        id = JLE;
    } else if (strcmp(s,"JMP") == 0 ){
        id = JMP;
    }
    return id;
}
static inline dest_id str_to_destid(const char *s){
    dest_id id = DEST_INVALID;

    if(s==NULL){
        id=JMP_NULL;
    }else if (strcmp(s,"M") == 0 ){
        id = M;
    }else if (strcmp(s,"D") == 0 ){
        id = D;
    }else if (strcmp(s,"MD") == 0 ){
        id = MD;
    }else if (strcmp(s,"A") == 0 ){
        id = A;
    }else if (strcmp(s,"AM") == 0 ){
        id = AM;
    }else if (strcmp(s,"AD") == 0 ){
        id = AD;
    }else if (strcmp(s,"AMD") == 0 ){
        id = AMD;
    }
    return id;
}

static inline comp_id str_to_compid(const char *s, int *a){
    comp_id id = COMP_INVALID;

    if(strcmp(s,"COMP_0") == 0 ){
        id = COMP_0;
        *a = 0;
    }else if (strcmp(s,"COMP_1") == 0 ){
        id = COMP_1;
        *a = 0;
    }else if (strcmp(s,"COMP_NEG_1") == 0 ){
        id = COMP_NEG_1;
        *a = 0;
    }else if (strcmp(s,"COMP_D") == 0 ){
        id = COMP_D;
        *a = 0;
    }else if (strcmp(s,"COMP_NEG_A") == 0 ){
        id = COMP_A;
        *a = 0;
    }else if (strcmp(s,"COMP_NotD") == 0 ){
        id = COMP_NotD;
        *a = 0;
    }else if (strcmp(s,"COMP_NotA") == 0 ){
        id = COMP_NotA;
        *a = 0;
    }else if (strcmp(s,"COMP_NegD") == 0 ){
        id = COMP_NegD;
        *a = 0;
    }else if (strcmp(s,"COMP_NegA") == 0 ){
        id = COMP_NegA;
        *a = 0;
    }else if (strcmp(s,"COMP_DPlus1") == 0 ){
        id = COMP_DPlus1;
        *a = 0;
    }else if (strcmp(s,"COMP_APlus1") == 0 ){
        id = COMP_APlus1;
        *a = 0;
    }else if (strcmp(s,"COMP_DMinus1") == 0 ){
        id = COMP_DMinus1;
        *a = 0;
    }else if (strcmp(s,"COMP_AMinus1") == 0){
        id = COMP_AMinus1;
        *a = 0;
    }else if (strcmp(s,"COMP_DPlusA") == 0 ){
        id = COMP_DPlusA;
        *a = 0;
    }else if (strcmp(s,"COMP_DMinusA") == 0 ){
        id = COMP_DMinusA;
        *a = 0;
    }else if (strcmp(s,"COMP_AMinusD") == 0 ){
        id = COMP_AMinusD;
        *a = 0;
    }else if (strcmp(s,"COMP_DAndA") == 0 ){
        id = COMP_DAndA;
        *a = 0;
    }else if (strcmp(s,"COMP_DOrA") == 0 ){
        id = COMP_DOrA;
        *a = 0;
    }else if (strcmp(s,"COMP_M") == 0 ){
        id = COMP_M;
        *a = 1;
    }else if (strcmp(s,"COMP_NotM") == 0 ){
        id = COMP_NotM;
        *a = 1;
    }else if (strcmp(s,"COMP_NegM") == 0 ){
        id = COMP_NegM;
        *a = 1;
    }else if (strcmp(s,"COMP_MPlus1") == 0 ){
        id = COMP_MPlus1;
        *a = 1;
    }else if (strcmp(s,"COMP_MMinus1") == 0 ){
        id = COMP_MMinus1;
        *a = 1;
    }else if (strcmp(s,"COMP_DPlusM") == 0 ){
        id = COMP_DPlusM;
        *a = 1;
    }else if (strcmp(s,"COMP_DMinusM") == 0 ){
        id = COMP_DMinusM;
        *a = 1;
    }else if (strcmp(s,"COMP_MMinusD") == 0 ){
        id = COMP_MMinusD;
        *a = 1;
    }else if (strcmp(s,"COMP_DAndM") == 0 ){
        id = COMP_DAndM;
        *a = 1;
    }else if (strcmp(s,"COMP_DOrM") == 0 ){
        id = COMP_DOrM;
        *a = 1;
    }  
}

