#ifndef _BinHeap_H
#define MinData -99999;

typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif