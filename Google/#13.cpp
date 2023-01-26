#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int i, int j, int n)
    {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};
        

        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(n,INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vis[0][0]=grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty())
        {
            int cur = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            for (int i = 0; i < 4; i++)
            {

                int cur_r = x + r[i];
                int cur_c = y + c[i];

                if (check(cur_r, cur_c, n) && vis[cur_r][cur_c]==INT_MAX)
                {


                    if(grid[cur_r][cur_c]>cur){
                        vis[cur_r][cur_c]=grid[cur_r][cur_c];
                        pq.push({vis[cur_r][cur_c], {cur_r, cur_c}});
                    }else{
                        vis[cur_r][cur_c]=cur;
                        pq.push({vis[cur_r][cur_c], {cur_r, cur_c}});

                    }
                }
            }

        }

        return vis[n-1][n-1];
    }
};