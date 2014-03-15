#include "stack.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));

    if(S == NULL)
        FatalError("Out of space!!!");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
        FatalError("Must use CreateStack first!");
    else
        while(!IsEmpty(S))
            Pop(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode TempCell;
    TempCell = malloc(sizeof(struct Node));
    
    if(TempCell ==  NULL)
        FatalError("Out of space!!!");
    else
    {
        TempCell->Element = X;
        TempCell->Next = S->Next;
        S->Next = TempCell;
    } 
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty stack");
    return 0;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if(IsEmpty(S))
        Error("Empty Stack");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }

}