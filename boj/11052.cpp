#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d",&n);
    int values[n+1];
    for (int i = 0; i < n; ++i)
        scanf("%d",values + i + 1);
    
    vector<int> dp(n+1,0);
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 0; j < i; ++j)
            dp[i] = max(values[i-j] + dp[j], dp[i]);

    }
    printf("%d\n",dp[n]);
    
    return 0;
}
