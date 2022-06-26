#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// estrutura para atribuir tipo ao valor de cada NODE
typedef enum {
    CHAR = 1,
    INT = 2,
    DOUBLE = 4,
    ARRAY = 8,
    STRING = 16,
    BLOCK = 32,
} TYPE;

#define NUM (INT | DOUBLE | CHAR)

#define IS_NUM(n) (n->type & NUM)

#define HAS_CHAR(a, b) ((a | b) & CHAR)

#define HAS_DOUBLE(a, b) ((a | b) & DOUBLE)

typedef struct {
    void *value;
    TYPE type;
} nodeStruct, *NODE; //sem um pointer as alteraçoes aos arrays eram locais

typedef struct {
    NODE array; // pointer para o array que constitui a stack em execução
    int sp;
    int size; //indica o tamanho alocado para o array
    NODE varList;  // pointer para o array onde são guardados os valores das variáveis
} stackStruct, *STACK;

typedef struct {
    int pos;
    void *value;
} organizerStruct, * tempOrganizer;

//funcoes que mexem na stack de forma simples
typedef void stackFunc (STACK stack);

//funções que redirecionam operadores de input para funções do tipo stackFunc
typedef void operHandler (char * * ptr, stackFunc *dist[], void *, STACK stack);

//funcoes de print
typedef void printFunc (void *);

typedef struct {
    stackFunc **dist;
    operHandler **handle;
    char *string;
} blockStruct, *BLOCKPTR;

void printInt (void *value);
void printDouble (void *value);
void printStr (void *value);
void printBlock (void *value);
void printChr (void *value);

//funções que não encaixam em stackFunc/auxiliares

void operHandlerDTAssign (operHandler *handle[]);

void varListAssign (NODE varList);

void stackFuncDTAssign (stackFunc *dist[]);

void push (STACK stack, long double val, TYPE t);

void generalPush (STACK stack, void * ptr, TYPE t);

void nodeToInt (NODE node);

void fullDeleteStack (STACK stack);

void deleteVarList (NODE varList);

void deleteStack (STACK stack);

void copyNode (NODE dest, NODE src);

void copyNodePush (STACK stack, NODE src);

int getSize (NODE node);

void deleteNode (NODE node);

void copyNode (NODE dest, NODE src);

void copyNodePush (STACK stack, NODE src);

void nodeToInt (NODE node);

STACK newStack (NODE varList);

void printInt (void *value);

void printDouble (void *value);

void printStr (void *value);

void printChr (void *value);

void debugPrintStack (STACK stack, printFunc *printDist[], int depth);

void debug (STACK stack);

BLOCKPTR copyBlock (BLOCKPTR block);

//operHandlers chamados por handle[]

void spaceHandler (char **ptr, stackFunc *dist[], void *, STACK stack);
void notHandler (char **ptr, stackFunc *dist[], void *, STACK stack);
void eHandler (char **ptr, stackFunc *dist[], void *, STACK stack);
void twoDotsHandler (char **ptr, stackFunc *dist[], void *, STACK stack);
void varHandler (char **ptr, stackFunc *dist[], void *, STACK stack);
void OtherOperHandler (char **ptr, stackFunc *dist[], void *, STACK stack);
void stringBuilder (char **ptr, stackFunc *dist[], void *, STACK stack);
void mainHandler (char * line, stackFunc *dist[], operHandler *handle[], STACK stack);

//Funções que constroem arrays e blocos 
char * blockBuilder (char * lineCrumbs, stackFunc *dist[], operHandler *handle[], STACK stack);
char * arrayBuilder (char * lineCrumbs, stackFunc *dist[], operHandler *handle[], STACK stack);

//stackFunctions chamadas por dist[]

//guiao 1
void add (STACK stack);
void sub (STACK stack);
void divis (STACK stack);
void mod (STACK stack);
void mult (STACK stack);
void inc (STACK stack);
void dec (STACK stack);
void expo (STACK stack);
void pop (STACK stack);
void and (STACK stack);
void or (STACK stack);
void xor (STACK stack);
void not (STACK stack);

//guiao 2
void toInt (STACK stack);
void toChar (STACK stack);
void toDouble (STACK stack);
void swap_top2 (STACK stack);
void duplicate (STACK stack);
void rotate_top3 (STACK stack);
void copy_nth (STACK stack);
void readl (STACK stack);

//guiao 3
void isEqual (STACK stack);
void isGreater (STACK stack);
void isLesser (STACK stack);
void negate (STACK stack);
void IfThenElse (STACK stack);
void top2Greater (STACK stack);
void top2Lower (STACK stack);
void top2Or (STACK stack);
void top2And (STACK stack);

//guiao 4
void range (STACK stack);
void whiteSpacer (STACK stack);
void newLineSpacer (STACK stack);
void readAll (STACK stack);

//guiao 5
void executew (STACK stack);

//etc
void debug (STACK stack);
void simpleDebug (STACK stack);
void toString (STACK stack);
void printTop (STACK stack);