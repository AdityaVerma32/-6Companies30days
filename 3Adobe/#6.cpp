#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    double sol(int k,int i,int j,int n,vector<vector<vector<double>>> &dp){
        if(i<0 || i>=n || j<0 || j>=n) return 0;
        if(k==0) return 1;

        if(dp[k][i][j]!=-1) return dp[k][i][j];

        double sum=0;
        if(i-2>=0 && j-1>=0)
        sum+=sol(k-1,i-2,j-1,n,dp)/8.0;     // done 

        if(i-2>=0 && j+1<n)
        sum+=sol(k-1,i-2,j+1,n,dp)/8.0;     // done
        
        if(i+2<n && j-1>=0)
        sum+=sol(k-1,i+2,j-1,n,dp)/8.0;

        if(i+2<n && j+1<n)
        sum+=sol(k-1,i+2,j+1,n,dp)/8.0;     // done

        if(j-2>=0 && i-1>=0)
        sum+=sol(k-1,i-1,j-2,n,dp)/8.0;

        if(j-2>=0 && i+1<n)
        sum+=sol(k-1,i+1,j-2,n,dp)/8.0;

        if(j+2<n && i+1<n)
        sum+=sol(k-1,i+1,j+2,n,dp)/8.0;     // done 

        if(j+2<n && i-1>=0)
        sum+=sol(k-1,i-1,j+2,n,dp)/8.0;     // done 

        return dp[k][i][j]=sum;

    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n,vector<double>(n,-1)));
        return sol(k,row,column,n,dp);
    }
};