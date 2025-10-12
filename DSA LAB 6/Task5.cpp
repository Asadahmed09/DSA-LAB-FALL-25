#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char st[500];
int top = -1;

void push(char c)
{
    st[++top] = c;
}

char popc()
{
    if (top == -1) return 0;
    return st[top--];
}

char peek()
{
    if (top == -1) return 0;
    return st[top];
}

int prec(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int isRightAssoc(char c)
{
    if (c == '^') return 1;
    return 0;
}

void infixToPostfix(char *s, char *out)
{
    top = -1;
    int i = 0;
    int j = 0;
    while (s[i])
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(s[i]))
        {
            while (isdigit(s[i]))
            {
                out[j++] = s[i++];
            }
            out[j++] = ' ';
        }
        else if (s[i] == '(')
        {
            push(s[i++]);
        }
        else if (s[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                out[j++] = popc();
                out[j++] = ' ';
            }
            popc();
            i++;
        }
        else
        {
            char op = s[i];
            while (top != -1 && peek() != '(' &&
                   (prec(peek()) > prec(op) || (prec(peek()) == prec(op) && !isRightAssoc(op))))
            {
                out[j++] = popc();
                out[j++] = ' ';
            }
            push(op);
            i++;
        }
    }
    while (top != -1)
    {
        out[j++] = popc();
        out[j++] = ' ';
    }
    if (j) j--;
    out[j] = 0;
}

long long evalPostfix(char *s)
{
    long long valst[500];
    int vt = -1;
    int i = 0;
    while (s[i])
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(s[i]))
        {
            long long num = 0;
            while (isdigit(s[i]))
            {
                num = num * 10 + (s[i++] - '0');
            }
            valst[++vt] = num;
        }
        else
        {
            long long b = valst[vt--];
            long long a = valst[vt--];
            char op = s[i++];
            long long res = 0;
            if (op == '+') res = a + b;
            else if (op == '-') res = a - b;
            else if (op == '*') res = a * b;
            else if (op == '/') res = a / b;
            else if (op == '^') res = (long long) pow((double)a, (double)b);
            valst[++vt] = res;
        }
    }
    return (vt >= 0) ? valst[vt] : 0;
}

int main()
{
    char in[200];
    char out[500];
    strcpy(in, "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
    infixToPostfix(in, out);
    printf("Infix: %s\n", in);
    printf("Postfix: %s\n", out);
    printf("Postfix Eval: %lld\n", evalPostfix(out));
}
