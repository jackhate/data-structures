#include "hashsep.h"

struct ListNode
{
	ElementType Element;
	Position Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if(TableSize < MinTableSize)
	{
		Error("Table Size too Small");
		return NULL;
	}

	H = malloc(sizeof(struct HashTable));
	if(H == NULL)
		FatalError("Out of space!");

	H->TableSize = NextPrime(TableSize);

	H->TheLists = malloc(sizeof(List) * H->TableSize);
	if(H->TheLists == NULL)
		FatalError("Out of space!");

	for(i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if(H->TheLists[i] == NULL)
			FatalError("Out of space!");
		else
			H->TheLists[i]->Next = NULL;
	}
}

void DestoryTable(HashTable H)
{
	int i;
	Position P, Tmp;

	if(H == NULL)
		return;

	for (i = 0; i < H->TableSize; ++i)
	{
		P = H->TheLists[i]->Next;
		H->TheLists[i]->Next = NULL;
		while(P != NULL)
		{
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}

		free(H->TheLists[i]);
	}

	free(H->TheLists);
	free(H);

}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];

	P = L->Next;
	while(P != NULL && P->Element != Key)
		P = P->Next;

	return P;
	
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List = L;

	Pos = Find(Key, H);
	if(Pos == NULL)
	{
		NewCell = malloc(sizeof(struct List Node));
		if(NewCell == NULL)
			FatalError("Out of space!");
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
		
	}
}


ElementType Retrieve(Position P)
{
	return P->Element;
}