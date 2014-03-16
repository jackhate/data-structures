#include "arrayStack.h"


int main(int argc, char const *argv[])
{
	Stack S;
	S = CreateStack(20);
	Push(1, S);
	Push(2, S);
	Push(3, S);
	Push(4, S);
	printf("%d\n", S->TopOfStack);

	Pop(S);
	printf("%d\n", S->TopOfStack);

	int a = Top(S);
	printf("%d\n", a);

	int b = TopAndPop(S);
	printf("%d %d\n", b, S->TopOfStack);

	return 0;
}