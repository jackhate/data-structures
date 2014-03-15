#include "cursor.h"

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];

void InitializeCursorSpace(void)
{
    int i;
    for (i = 0; i < SpaceSize; ++i)
    {
        CursorSpace[i].Next = i+1;
    }
    CursorSpace[SpaceSize - 1].Next = 0;
}

static Position CursorAlloc()
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    return P;
}

static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

int IsEmpty(const List L)
{
    return CursorSpace[L].Next == 0;
}

int IsLast(const Position P, const List L)
{
    return return CursorSpace[P].Next == 0;
}

Position Find(ElementType X, const List L)
{
    Position P;
    P = CursorSpace[L].Next;
    while(P && CursorSpace[P].Element != X)
    {
        P = CursorSpace[P].Next;
    }

    return P;
}

Position FindPrevious(ElementType X, const List L)
{
    Position P;
    P = L;
    while(CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
    {
        P = CursorSpace[P].Next;
    }

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);

    if(!IsLast(P, L))
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = CursorAlloc();

    if(TmpCell == 0)
        FatalError("Out of Space!");

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}