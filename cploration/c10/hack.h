#include <stdint.h>

#define NUM_PREDEFINED_SYMBOLS 23

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
    } else if (*s == "JGT"){
        id = JGT;
    } else if (*s == "JEQ"){
        id = JEQ;
    } else if (*s == "JGE"){
        id = JGE;
    } else if (*s == "JLT"){
        id = JLT;
    } else if (*s == "JNE"){
        id = JNE;
    } else if (*s == "JLE"){
        id = JLE;
    } else if (*s == "JMP"){
        id = JMP;
    }
    return id;
}
static inline dest_id str_to_destid(const char *s){
    dest_id id = DEST_INVALID;

    if(s==NULL){
        id=JMP_NULL;
    }else if (*s == "M"){
        id = M;
    }else if (*s == "D"){
        id = D;
    }else if (*s == "MD"){
        id = MD;
    }else if (*s == "A"){
        id = A;
    }else if (*s == "AM"){
        id = AM;
    }else if (*s == "AD"){
        id = AD;
    }else if (*s == "AMD"){
        id = AMD;
    }
    return id;
}

static inline comp_id str_to_compid(const char *s, int *a){
    comp_id id = COMP_INVALID;

    if(strcmp(s,"COMP_0") == 0 ){
        id = COMP_0;
        *a = 0;
    }else if (*s == "COMP_1"){
        id = COMP_1;
        *a = 0;
    }else if (*s == "COMP_NEG_1"){
        id = COMP_NEG_1;
        *a = 0;
    }else if (*s == "COMP_D"){
        id = COMP_D;
        *a = 0;
    }else if (*s == "COMP_A"){
        id = COMP_A;
        *a = 0;
    }else if (*s == "COMP_NotD"){
        id = COMP_NotD;
        *a = 0;
    }else if (*s == "COMP_NotA"){
        id = COMP_NotA;
        *a = 0;
    }else if (*s == "COMP_NegD"){
        id = COMP_NegD;
        *a = 0;
    }else if (*s == "COMP_NegA"){
        id = COMP_NegA;
        *a = 0;
    }else if (*s == "COMP_DPlus1"){
        id = COMP_DPlus1;
        *a = 0;
    }else if (*s == "COMP_APlus1"){
        id = COMP_APlus1;
        *a = 0;
    }else if (*s == "COMP_DMinus1"){
        id = COMP_DMinus1;
        *a = 0;
    }else if (*s == "COMP_AMinus1"){
        id = COMP_AMinus1;
        *a = 0;
    }else if (*s == "COMP_DPlusA"){
        id = COMP_DPlusA;
        *a = 0;
    }else if (*s == "COMP_DMinusA"){
        id = COMP_DMinusA;
        *a = 0;
    }else if (*s == "COMP_AMinusD"){
        id = COMP_AMinusD;
        *a = 0;
    }else if (*s == "COMP_DAndA"){
        id = COMP_DAndA;
        *a = 0;
    }else if (*s == "COMP_DOrA"){
        id = COMP_DOrA;
        *a = 0;
    }else if (*s == "COMP_M"){
        id = COMP_M;
        *a = 1;
    }else if (*s == "COMP_NotM"){
        id = COMP_NotM;
        *a = 1;
    }else if (*s == "COMP_NegM"){
        id = COMP_NegM;
        *a = 1;
    }else if (*s == "COMP_MPlus1"){
        id = COMP_MPlus1;
        *a = 1;
    }else if (*s == "COMP_MMinus1"){
        id = COMP_MMinus1;
        *a = 1;
    }else if (*s == "COMP_DPlusM"){
        id = COMP_DPlusM;
        *a = 1;
    }else if (*s == "COMP_DMinusM"){
        id = COMP_DMinusM;
        *a = 1;
    }else if (*s == "COMP_MMinusD"){
        id = COMP_MMinusD;
        *a = 1;
    }else if (*s == "COMP_DAndM"){
        id = COMP_DAndM;
        *a = 1;
    }else if (*s == "COMP_DOrM"){
        id = COMP_DOrM;
        *a = 1;
    }  
}

