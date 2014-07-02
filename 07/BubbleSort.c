#include "stdio.h"

void swap(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}

void BubbleSort(int A[], int n)
{
	int i, j;
	for (j = 0; j < n-1; ++j)
	{
		for (i = 0; i < n-1-j; ++i)
		{
			if(A[i] > A[i+1])
				swap(A[i], A[i+1]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int A[6] = {34, 8, 64, 51, 32, 21};
	BubbleSort(A, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d \n", A[i]);
	}
	return 0;
}
