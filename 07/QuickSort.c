#include "stdio.h"
#define Cutoff (3)

void InsertSort(int A[], int n)
{
	int i, P;
	for(P = 1;P < n;P++)
	{
		int temp = A[P];
		for(i = P;i > 0 && A[i-1] > temp;i--)
			A[i] = A[i-1];

		A[i] = temp;
	}
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

int Median3(int A[], int Left, int Right)
{
	int Center = (Left + Right)/2;

	if(A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if(A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if(A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);

	Swap(&A[Center], &A[Right-1]);
	return A[Right-1];
}

void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;

	if(Left + Cutoff <= Right)
	{
		Pivot = Median3(A, Left, Right);
		i = Left;
		j = Right-1;

		for ( ; ; )
		{
			while(A[++i] < Pivot){}
			while(A[--j] > Pivot){}
			if(i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}

		Swap(&A[i], &A[Right-1]);

		Qsort(A, Left, i-1);
		Qsort(A, i+1, Right);
	}
	else
	{
		InsertSort(A + Left, Right - Left + 1);
	}
}

int main(int argc, char const *argv[])
{
	int A[10] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
	Qsort(A, 0, 9);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d \n", A[i]);
	}
	return 0;
}