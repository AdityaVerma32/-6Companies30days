#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double sol(int cur,int n,int k,int nums,vector<double> &dp){
        if(cur>=k){
            if(cur<=n) return 1;
            else return 0;
        }

        if(dp[cur]!=-1) return dp[cur];

        double ans=0;

        for(double l=1;l<=nums;l++){
            ans+=sol(cur+l,n,k,nums,dp);
        }

        return dp[cur]=ans/nums;
    }
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k+maxPts+1,0);
        // return sol(0,n,k,maxPts,dp);
        double sum=0;

        // int i=k;
        // while(i<=n){
        //     dp[i++]=1;
        // }

        for(int i=k;i<(k+maxPts);i++){
            if(i<=n) dp[i]=1;
            else dp[i]=0;

            sum+=dp[i];
        }

        for(int cur=k-1;cur>=0;cur--){

            // double ans=0;

            // for(double l=1;l<=maxPts;l++){

            //     ans+=dp[cur+l];
            // }

            dp[cur]=sum/maxPts;

            sum+=dp[cur];
            sum-=dp[cur+maxPts];
        }
        return dp[0];
    }
};