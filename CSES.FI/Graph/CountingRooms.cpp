#include <bits/stdc++.h>

using namespace std;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char grid[10001][10001];
bool visited[10001][10001];
int m,n,count_room = 0;




void dfs(int x, int y)
{
    visited[x][y]=true;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x+dx[i], y1 = y+dy[i];
        if(!visited[x1][y1] && grid[x1][y1] == '.')
        {
            dfs(x1, y1);
        }
    }
    
}

int main()
{
    cin >> m>>n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                count_room++;
            }
        }
    }

cout << count_room;
return 0;

}