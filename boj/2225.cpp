#include <vector>

using namespace std;
int TOMOD = 1000000000;

int helper(vector<vector<int> > &dp,int n, int k)
{
    if (k <= 1) 
        return k;

    if (dp[n][k] != -1) 
        return dp[n][k];

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += helper(dp,n-i,k-1) % TOMOD;
        ans = ans % TOMOD;
    }
    dp[n][k] = ans % TOMOD;
    return ans;
}
int main()
{
    int n = 0, k = 0;
    scanf("%d",&n);
    scanf("%d",&k);

    vector<vector<int> > dp(n+1,vector<int>(k+1,-1));
    printf("%d\n",helper(dp,n,k));

    return 0;
}
