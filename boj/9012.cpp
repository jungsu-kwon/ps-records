#include <string>
#include <stack>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char ps[100000+1];
    scanf("%s",&ps);
    string strPs = string(ps);
    stack<char> parens;

    char prevChar = ' ';
    int ans = 0;
    for (auto ch: strPs)
    {
        if (ch == '(')
            parens.push('(');
        else
        {
            if (prevChar == '(')
            {
                parens.pop();
                ans += parens.size();
            }
            else 
            {
                ans += 1;
                parens.pop();
            }

        }
        prevChar = ch;
    }
    printf("%d\n",ans);

    return 0;
}
