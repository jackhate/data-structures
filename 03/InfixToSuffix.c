#include "infixToSuffix.h"

void infixToSuffix(const char *infix, char *suffix)
{
    
    Stack signStack;
    signStack = CreateStack(20);
    int i = 0;

    char *pointer = infix;
    while(*pointer != '\0')
    {
        switch(*pointer)
        {
            case '(':
                Push(*pointer, signStack);
                break;
        
            case ')':
                Pop(signStack);
                while(Top(signStack) != '(')
                    suffix[i++] = TopAndPop(signStack);
                Pop(signStack);
                break;
            
            case '+':
                while(!IsEmpty(signStack) &&(Top(signStack) == '*' || Top(signStack) == '+'))
                    suffix[i++] = TopAndPop(signStack);
                Push('+', signStack);
                break;
            
            case '*':
                Push(*pointer, signStack);
                break;

            default:
                suffix[i++] = *pointer;
        }
        pointer++;
    }
    
    while(!IsEmpty(signStack))
        suffix[i++] = TopAndPop(signStack);

    suffix[i] = '\0';
}

int CalculateSuffix(const char *suffix)
{
    int ans;
    char anschar;
    int operand1, operand2;
    Stack ansStack;
    ansStack = CreateStack(20);
    char *pointer;
    pointer = suffix;
    
    
    while(*pointer != '\0')
    {
        switch(*pointer)
        {
            case '*':
                operand1 = TopAndPop(ansStack) - '0';
                operand2 = TopAndPop(ansStack) - '0';
                anschar = operand1 * 
        }
    }
}