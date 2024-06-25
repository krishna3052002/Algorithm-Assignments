#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> v[N];
bool vis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (!v[x].empty())
        {
            sort(v[x].begin(), v[x].end(), greater<int>());
            for (int c : v[x])
            {
                cout << c << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}