#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long mod=1e9+7;
        vector<long> dp(n+1,0);
        long temp=0;
        dp[1]=1;
        for(long i=2;i<=n;i++){
            long a=0,b=0;
            if(i-delay>0)
            a=dp[i-delay];
            if(i-forget>0)
            b=dp[i-forget];

            temp=(temp+a-b+mod)%mod;
            
            dp[i]=temp;
        }
        long int ans=0;
        for(int i=n;i>=(n-forget+1);i--){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};