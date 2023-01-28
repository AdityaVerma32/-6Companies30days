#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int sol(int startPos, int endPos, int k,vector<vector<int>>& dp) {
        if(k==0){
            if(startPos==endPos) return 1;
            else return 0;
        }

        if(dp[startPos][k]!=-1) return dp[startPos][k];

        int back=sol(startPos-1,endPos,k-1,dp);
        int next=sol(startPos+1,endPos,k-1,dp);

        return dp[startPos][k]=(back+next)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1201;
        endPos+=1201;
        vector<vector<int>> dp(4000,vector<int>(k+1,-1));
        return sol(startPos,endPos,k,dp) ;
    }
};