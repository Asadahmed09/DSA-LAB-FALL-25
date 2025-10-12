#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
char st2[500];
int tp = -1;

void push2(char c)
{
    st2[++tp] = c;
}
char pop2()
{
    if (tp == -1) return 0;
    return st2[tp--];
}

char peek2()
{
    if (tp == -1) return 0;
    return st2[tp];
}

int prec2(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

bool rightA(char c)
{
    return c == '^';
}

void revstr(string &s)
{
    int i = 0;
    int j = (int)s.size() - 1;
    while (i < j)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

void swappar(string &s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
}

void infixToPostfixLocal(const string &s, string &out)
{
    tp = -1;
    out.clear();
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(s[i]))
        {
            while (i < n && isdigit(s[i]))
            {
                out.push_back(s[i++]);
            }
            out.push_back(' ');
        }
        else if (s[i] == '(')
        {
            push2(s[i++]);
        }
        else if (s[i] == ')')
        {
            while (tp != -1 && peek2() != '(')
            {
                out.push_back(pop2());
                out.push_back(' ');
            }
            pop2();
            i++;
        }
        else
        {
            char op = s[i];
            while (tp != -1 && peek2() != '(' &&
                  (prec2(peek2()) > prec2(op) || (prec2(peek2()) == prec2(op) && !rightA(op))))
            {
                out.push_back(pop2());
                out.push_back(' ');
            }
            push2(op);
            i++;
        }
    }
    while (tp != -1)
    {
        out.push_back(pop2());
        out.push_back(' ');
    }
    if (!out.empty() && out.back() == ' ') out.pop_back();
}

void infixToPrefix(const string &s, string &out)
{
    string tmp = s;
    revstr(tmp);
    swappar(tmp);
    string post;
    infixToPostfixLocal(tmp, post);
    revstr(post);
    out = post;
}

long long evalPrefix(const string &s)
{
    long long val[500];
    int vi = -1;
    int n = s.size();
    int i = n - 1;
    while (i >= 0)
    {
        if (s[i] == ' ')
        {
            i--;
            continue;
        }
        if (isdigit(s[i]))
        {
            int j = i;
            while (j >= 0 && isdigit(s[j])) j--;
            long long num = 0;
            for (int k = j + 1; k <= i; k++) num = num * 10 + (s[k] - '0');
            val[++vi] = num;
            i = j;
        }
        else
        {
            long long a = val[vi--];
            long long b = val[vi--];
            char op = s[i--];
            long long r = 0;
            if (op == '+') r = a + b;
            else if (op == '-') r = a - b;
            else if (op == '*') r = a * b;
            else if (op == '/') r = a / b;
            else if (op == '^') r = (long long) pow((double)a, (double)b);
            val[++vi] = r;
        }
    }
    return vi >= 0 ? val[vi] : 0;
}

int main()
{
    string in = "( 3 + 4 ) * 5 - 6";
    string pre;
    infixToPrefix(in, pre);
    cout << "Infix: " << in << '\n';
    cout << "Prefix: " << pre << '\n';
    cout << "Prefix Eval: " << evalPrefix(pre) << '\n';
}
