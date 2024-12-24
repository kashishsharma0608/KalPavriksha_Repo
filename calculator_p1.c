#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
bool is_space(char ch)
{
    return ch == ' ';
}
bool is_digit(char ch)
{
        return (ch>='0'&&ch<='9');
    
}
bool isoperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int preced(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
}
int evalt(int n1, int n2, char ch)
{

    switch (ch)
    {
    case '+':
        return n1 + n2;
    case '-':

        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
     if(n2==0){
        printf("divison by zero");
        exit(1); 
     }
     else{
        return (n1 / n2);
     }
      
    }
    return 0;
}
int calculate(char *expr)
{
    int *val;
    char *opt;

    int j = 0, k = 0;
    val = (int *)malloc(100 * sizeof(int));
    opt = (char *)malloc(100 * sizeof(char));
    int size = strlen(expr);
    for (int i = 0; i < size; i++)
    {
        if (is_space(expr[i]))
        {
            continue; 
        }
        else if (is_digit(expr[i]))
        {
            int num = 0;

           
            while (i < size && is_digit(expr[i]))
            {
                num = num*10 + (expr[i] - '0'); 
                i++;
            }
            i--;
            val[j++] = num;
        }
        else if (isoperator(expr[i]))
        { 
            while (k > 0 && preced(opt[k - 1]) >= preced(expr[i]))
            {
                int num2 = val[--j];
                int num1 = val[--j];
                char op = opt[--k];
                val[j++] = evalt(num1, num2, op);
            }
            opt[k++] = expr[i];
        }
    }
    // printf("%d%d", j, k);

    while (k > 0)
    {
        int num2 = val[--j];
        int num1 = val[--j];
        char op = opt[--k];
        val[j++] = evalt(num1, num2, op);
    }
    return val[0];
}

int main()
{
    char *expr;
    printf("enter the expression:");
    expr = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", expr);
    int result = calculate(expr);
    printf("%d", result);
    return 0; 
}