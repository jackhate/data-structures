#include "binheap.h"

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	H = malloc(sizeof(struct HeapStruct));
	if(H == NULL)
		FatalError("Out of Space!");

	H->Elements = malloc(sizeof(ElementType)*(MaxElements+1));

	if(H->Elements == NULL)
		FatalError("Out of Space!");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;

	return H;

}

int IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity;
}

int IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if(IsFull(H))
		FatalError("Priority queue if full!!!");

	for(i = ++H->Size; X < H->Elements[i/2];i = i/2)
		H->Elements[i] = H->MaxElements[i/2];

	H->Elements[i] = X;
}

ElementType FindMin(PriorityQueue H)
{
	if(IsEmpey(H))
	{
		Error("Priority queue is empty");
		return H->Elements[0];
	}
	
	return H->Elements[1];
}

ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;

	if(IsEmpey(H))
	{
		Error("Priority queue is empty");
		return H->Elements[0];
	}

	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	for(i = 1;i*2 <= H->Size; i = Child)
	{
		Child = i*2;

		if(Child != H->Size && H->Elements[Child+1] < H->Elements[Child])
			Child++;

		if(LastElement > H->Elements[Child])
			H->Elements[i] = Elements[Child];
		else
			break;
	}

	H->Elements[i] = LastElement;

	return MinElement;

}

