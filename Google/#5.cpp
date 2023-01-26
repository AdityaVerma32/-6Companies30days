#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sol(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return false;
        if(grid[i][j]==1) return true;

        grid[i][j]=1;
        int left=sol(i,j-1,grid);
        int right=sol(i,j+1,grid);
        int up=sol(i-1,j,grid);
        int down=sol(i+1,j,grid);

        return (left && right && up && down);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int c=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0 && sol(i,j,grid)){
                    c++;
                }
            }
        }
        return c;
    }
};