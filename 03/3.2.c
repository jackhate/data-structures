#include "list.h"

void PrintLots(List L, List P)
{
	Position PositionP, PositionL;
    PositionP = First(P);
    PositionL = First(L);
    int counter = 1;

    while(PositionP != NULL && PositionL != NULL)
    {
        if(PositionP->Element == counter++)
        {
            printf("%d\n", PositionL->Element);
            PositionP  = PositionP->Next;
        }

        PositionL = PositionL->Next;
    }
}