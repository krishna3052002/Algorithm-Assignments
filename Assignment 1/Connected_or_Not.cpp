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
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if(x==y)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool flag = false;
        for (int c : v[x])
        {
            if (c == y)
            {
                flag = true;
            }
        }
        if (flag == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}