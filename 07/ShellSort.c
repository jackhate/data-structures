#include "stdio.h"

void ShellSort(int A[], int n)
{
	int i, j, Increment;
	int tmp;

	for(Increment = n/2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i < n; ++i)
		{
			tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if(A[j - Increment] > tmp)
					A[j] = A[j-Increment];
				else
					break;
			}
			A[j] = tmp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int A[6] = {34, 8, 64, 51, 32, 21};
	ShellSort(A, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d \n", A[i]);
	}
	return 0;
}