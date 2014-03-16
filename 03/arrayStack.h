#ifndef _Stack_h

#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;
struct StackRecord;
typedef struct StackRecord *Stack;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

void Error(const char* msg);
void FatalError(const char* msg);



#endif