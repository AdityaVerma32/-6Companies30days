#include<bits/stdc++.h>
using namespace std;



 int maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        vector<vector<int>> dp(12,vector<int>(numArrows+1,0));
        
        for(int i=1;i<12;i++){
            for(int j=1;j<=numArrows;j++){
                int ans=dp[i-1][j];
                if(j>aliceArrows[i]){
                    ans=max(ans,dp[i-1][j-aliceArrows[i]]+i);
                }
                dp[i][j]= ans;
            }
        }
        return dp[11][numArrows];
    }

int main(){
    vector<int> arr(12);
    arr={0,0,1,0,0,0,0,0,0,0,0,2};
    int ans=maximumBobPoints(3,arr);

    cout<<ans<<endl;
}