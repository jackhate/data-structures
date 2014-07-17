#include "stdio.h"
#define LeftChild(i) (2*(i) + 1)

void PercDown(int A[], int i, int N)
{
	int Child;
	int Tmp;

	for(Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);

		if(Child != N-1 && A[Child + 1] > A[Child])
			Child++;

		if(A[Child] > Tmp)
			A[i] = A[Child];
		else
			break;
	}

	A[i] = Tmp;
}

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapSort(int A[], int N)
{
	int i;
	for(i = N/2; i >=0; i--)
		PercDown(A, i, N);

	for(i = N-1; i > 0;i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

int main(int argc, char const *argv[])
{
	int A[6] = {34, 8, 64, 51, 32, 21};
	HeapSort(A, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d \n", A[i]);
	}
	return 0;
}