#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int dis[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char adj[1005][1005];
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
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && adj[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a, b};
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
            cin >> adj[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            parent[i][j] = {-1, -1};
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 'R')
            {
                bfs(i, j);
            }
        }
    }
    vector<pair<int, int>> path;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 'D')
            {
                // cout<<dis[i][j]<<endl;
                pair<int, int> x = {i, j};
                while (x.first != -1 && x.second != -1)
                {
                    path.push_back({x.first, x.second});
                    x = {parent[x.first][x.second].first, parent[x.first][x.second].second};
                    // cout << x.first << " " << x.second << endl;
                }
                break;
            }
        }
    }
    for (pair<int, int> r : path)
    {
        // cout<<r.first<<" "<<r.second<<endl;
        int i = r.first;
        int j = r.second;
        if(adj[i][j]!='R' && adj[i][j]!='D')
        {
         adj[i][j] = 'X';
        }
    }
    // cout << dis[0][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<adj[i][j];
        }
        cout<<endl;
    }
    return 0;
}