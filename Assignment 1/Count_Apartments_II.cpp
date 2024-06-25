#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool flag=false;
int r;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    r++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj]!='#')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    vector<int>v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
   
     memset(vis, false, sizeof(vis));
   int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           if(a[i][j]=='.' && vis[i][j]==false)
           {
           r=0;
           dfs(i,j);
           v.push_back(r);
           c++;
           }
        }
    }
   if(c!=0)
   {
    sort(v.begin(),v.end());
    for(int x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
   }
   else
   {
     cout << c << endl;
   }
    return 0;
}
