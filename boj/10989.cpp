#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int MAXNUM=10000;
int main()
{
    int n = 0;
    scanf("%d",&n);

    vector<int> numbers(MAXNUM+1,0);

    int number = 0;


    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&number);
        numbers[number] += 1;
    }

    for (int i = 0; i < MAXNUM+1; ++i)
    {
        for (int j = 0; j < numbers[i]; ++j)
            printf("%d\n",i);
    }

    return 0;
}

