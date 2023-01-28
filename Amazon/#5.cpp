#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int i,int j,int n){
        if(i-1>=0 && i+1<n && j-1>=0 && j+1<n) return true;
        else return false;
    }
    int cal(int i,int j,vector<vector<int>> grid){
        int ans=0;
        ans+=grid[i][j];
        ans+=grid[i-1][j-1]; 
        ans+=grid[i+1][j-1];
        ans+=grid[i-1][j];
        ans+=grid[i+1][j];
        ans+=grid[i-1][j+1];
        ans+=grid[i+1][j+1];

        return ans;
    }
    int maxSum(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(check(i,j,n)){
                    ans=max(ans,cal(i,j,grid));
                }

            }
        }
        return ans;
    }
};