#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
const int M=1e3;
bool vis[N][M];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[N][M];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int x = par.first, y = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj]!='-')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
               
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    int di,dj;
    cin>>di>>dj;
    memset(vis, false, sizeof(vis));
   
    bfs(si, sj);
    if(vis[di][dj]!=false)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}