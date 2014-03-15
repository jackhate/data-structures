#include "arratStack.h"

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
    Stack S;

    if(MaxElements < MinStackSize)
        Error("Stack size is too small");

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL)
        FatalError("Out of space!!!");

    S->Array = malloc(MaxElements * sizeof(struct StackRecord));
    if(S->Array == NULL)
        FatalError("Out of space!!!");

    MakeEmpty(S);

    return S;

}

void DisposeStack(Stack S)
{
    if(S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == (Capacity-1);
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Full Stack");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty Stack");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty Stack");
    else
        S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Empty Stack");
    return 0;
}