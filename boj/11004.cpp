#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 0, k = 0;
    scanf("%d",&n);
    scanf("%d",&k);

    long number = 0;
    vector<long> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%ld",&number);
        numbers[i] = number;
    }

    nth_element(numbers.begin(),numbers.begin()+k-1,numbers.end());
    printf("%ld\n",numbers[k-1]);

    return 0;
}

