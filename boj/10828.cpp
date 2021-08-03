#include <stack>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d",&n);
    stack<int> numbers;

    int number = 0;
    for (int i = 0; i < n; ++i)
    {
        char func[10];
        scanf("%s",func);
        if (!strcmp(func,"push"))
        {
            scanf("%d",&number);
            numbers.push(number);
        }
        else if (!strcmp(func,"top"))
        {
            int numberToPrint = numbers.size()? numbers.top() : -1;
            printf("%d\n",numberToPrint);
        }
        else if (!strcmp(func,"pop"))
        {
            int numberToPrint = numbers.size()? numbers.top() : -1;
            printf("%d\n",numberToPrint);
            if (numbers.size())
                numbers.pop();
        }
        else if (!strcmp(func,"size"))
        {
            printf("%d\n",numbers.size());
        }
        else{
            int numberToPrint = numbers.size() ? 0 : 1;
            printf("%d\n",numberToPrint);
        }
    }

    return 0;
}
