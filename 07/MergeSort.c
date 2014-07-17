#include "stdio.h"
#include "malloc.h"

void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	NumElements = RightEnd - Lpos + 1;
	TmpPos = Lpos;

	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(A[Lpos] < A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	}

	while(Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];

	while(Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	for(i = 0;i < NumElements;i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}

void MSort(int A[], int TmpArray[], int Left, int Right)
{
	int Center;
	if(Left < Right)
	{
		Center = (Left + Right)/2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center+1, Right);
		Merge(A, TmpArray, Left, Center+1, Right);
	}
}

void MergeSort(int A[], int N)
{
	int *TmpArray = (int *)malloc(sizeof(int)*N);
	MSort(A, TmpArray, 0, N-1);
	free(TmpArray);
}


int main(int argc, char const *argv[])
{
	int A[6] = {34, 8, 64, 51, 32, 21};
	MergeSort(A, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d \n", A[i]);
	}
	return 0;
}