#include "stdint.h"


#define SYMBOL_TABLE_SIZE 100

typedef int16_t hack_addr;

typedef struct Symbol{
    char *name;
    hack_addr addr;

};