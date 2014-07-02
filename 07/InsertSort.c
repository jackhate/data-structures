#include "stdio.h"

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

int main(int argc, char const *argv[])
{
	int A[6] = {34, 8, 64, 51, 32, 21};
	InsertSort(A, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d \n", A[i]);
	}
	return 0;
}