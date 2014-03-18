#include "list.h"

List ReverseList(List L)
{
    PoistionPre = NULL;
    PoistionCur = L;
    PoistionNext = L->Next;

    while(PoistionNext != NULL)
    {
        PoistionCur->Next = PoistionPre;
        PoistionPre = PoistionCur;
        PoistionCur = PoistionNext;
        PoistionNext = PoistionNext->PoistionNext;
    }
    PoistionCur->Next = PoistionPre;
    return PoistionCur;
}