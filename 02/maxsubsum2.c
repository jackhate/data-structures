int max2(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}



int main(int argc, char const *argv[])
{
    int A[7] = {-3, 5, -2, -1, 2, 6, -2};
    int i;
    int max = 0;
    int max_back = 0;

    for(i = 0; i < 7; i++)
    {
        max += A[i];
        if(A[i] > 0)
            max_back = max;
        if(max < 0)
        {
            max = 0;
            max_back = 0;
        }
            
    }

    
    printf("%d\n", max2(max, max_back));    
    return 0;
}

