#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5 + 5;
ll dp[N];
bool is_n_Possible(ll cur, ll n)
{
    if (cur == n)
    {
        return true;
    }
    if (cur > n)
    {
        return false;
    }
    if (dp[cur] != -1)
    {
        return dp[cur];
    }
    else
    {
        bool op1 = is_n_Possible(cur + 3, n);
        bool op2 = is_n_Possible(cur * 2, n);
        return dp[cur] = op1 || op2;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }
        if (is_n_Possible(1, n))
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}