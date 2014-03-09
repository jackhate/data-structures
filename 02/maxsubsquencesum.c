static int MaxSubSum(const int A[], int Left, int Right)
{
    int middle, LeftMax, RightMax, MiddleMax, LeftMiddleMax, MiddleRightMax, LeftMiddleSum, MiddleRightSum;
    int i;   
    
    if(Left == Right)
    {
        // if(A[Left] < 0)
        //     return 0;
        // else
            return A[Left];
    }
        

    middle = (Left + Right)/2;

    LeftMax = MaxSubSum(A, Left, middle);
    RightMax = MaxSubSum(A, middle+1, Right);

    LeftMiddleMax = A[middle];
    LeftMiddleSum = 0;
    for(i = middle; i >= Left; i--)
    {
        LeftMiddleSum += A[i];
        if(LeftMiddleSum >= LeftMiddleMax)
            LeftMiddleMax = LeftMiddleSum;
    }

    MiddleRightMax = A[middle+1];
    MiddleRightSum = 0;
    for(i = middle+1; i <= Right; i++)
    {
        MiddleRightSum += A[i];
        if(MiddleRightSum >= MiddleRightMax)
            MiddleRightMax = MiddleRightSum;
    }

    MiddleMax = LeftMiddleMax + MiddleRightMax;

    return Max(LeftMax, RightMax, MiddleMax);

}

int Max(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if (b >= c)
        return b;
    else
        return c;
}

int main(int argc, char const *argv[])
{
    int A[8] = {-3, 5, -2, -1, 2, 6, -2};
    int max = MaxSubSum(A, 0, 6);
    printf("%d\n", max);
    return 0;
}