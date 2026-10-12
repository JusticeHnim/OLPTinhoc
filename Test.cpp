#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX_VAL = 1e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> cnt(MAX_VAL, 0);

    int n;
    if(!(cin >> n)) return 0;

    int MAX_A = 0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        MAX_A = max(MAX_A, x);
    }

    vector<long long> dp(MAX_A + 1, 0);
    dp[0] = 0;
    if(MAX_A>=1)
        dp[1] = 1LL*1*cnt[1];
    for(int i=2; i<=MAX_A; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + 1LL*i*cnt[i]);
    }

    cout << dp[MAX_A] << "\n";

    return 0;
}